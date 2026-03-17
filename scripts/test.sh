#!/bin/bash

# Test script for CXY Playground
# Runs build tests on all snippets against a deployed server
# Can be sourced or run directly

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Helper function for colored output
print_color() {
    printf "%b\n" "$1"
}

# Default values
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
# Use SOURCE_DIR if available (when sourced from Cxyfile), otherwise use SCRIPT_DIR
BASE_DIR="${SOURCE_DIR:-${SCRIPT_DIR}/..}"
SNIPPETS_DIR="${BASE_DIR}/snippets"
CLI_SCRIPT="${BASE_DIR}/scripts/cli.sh"
HOST="${CXY_SERVER_HOST:-0.0.0.0:8100}"
BUILD_DIR="${BUILD_DIR:-${BASE_DIR}/.cxy/build}"
DEPS_ARCH_BIN_DIR="${DEPS_ARCH_BIN_DIR:-${BASE_DIR}/.cxy/deps/arch/bin}"
TEST_LOG_DIR="${BUILD_DIR}/tests"

# Global variables
SERVER_PID=""
SERVER_LOG=""
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Start server in background
start_server() {
    local server_port="${CXY_SERVER_PORT:-8100}"

    # Create test log directory
    mkdir -p "${TEST_LOG_DIR}"
    SERVER_LOG="${TEST_LOG_DIR}/test-${SERVER_PID}.log"

    print_color "${BLUE}Starting server on port $server_port...${NC}"

    # Add isolate to PATH and start server, redirect output to log
    PATH="${PATH}:${DEPS_ARCH_BIN_DIR}" CXY_SERVER_PORT="$server_port" "${BUILD_DIR}/app" > "${SERVER_LOG}" 2>&1 &
    SERVER_PID=$!
    SERVER_LOG="${TEST_LOG_DIR}/test-${SERVER_PID}.log"

    print_color "${GREEN}Server started (PID: $SERVER_PID)${NC}"
    printf "Server log: %s\n" "${SERVER_LOG}"

    # Wait for server to start
    echo "Waiting for server to be ready..."
    sleep 2

    # Check if server is still running
    if ! kill -0 "$SERVER_PID" 2>/dev/null; then
        print_color "${RED}Error: Server failed to start${NC}"
        # Kill the failed server process
        kill "$SERVER_PID" 2>/dev/null || true
        wait "$SERVER_PID" 2>/dev/null || true
        SERVER_PID=""
        return 1
    fi

    echo ""
    return 0
}

# Cleanup and stop server
cleanup_server() {
    if [ -n "$SERVER_PID" ]; then
        echo ""
        print_color "${BLUE}Stopping server (PID: $SERVER_PID)...${NC}"
        kill "$SERVER_PID" 2>/dev/null || true
        wait "$SERVER_PID" 2>/dev/null || true
        print_color "${GREEN}Server stopped${NC}"
    fi
}

# Check if server is running
check_server() {
    print_color "${BLUE}Checking if server is running at $HOST...${NC}"
    if ! curl -s -f "http://$HOST/health" > /dev/null 2>&1; then
        print_color "${RED}Error: Server is not running at $HOST${NC}"
        print_color "${YELLOW}Please start the server first${NC}"
        return 1
    fi
    print_color "${GREEN}Server is running${NC}"
    echo ""
    return 0
}

# Run a single test
_runTest() {
    local snippet_file="$1"
    local snippet_name=$(basename "$snippet_file" .cxy)

    TOTAL_TESTS=$((TOTAL_TESTS + 1))

    # Check if first line contains @TEST marker
    local first_line=$(head -n 1 "$snippet_file")
    local command="build"
    if echo "$first_line" | grep -q "@TEST"; then
        command="test"
    fi

    print_color "${BLUE}[Test $TOTAL_TESTS] Testing: $snippet_name (command: $command)${NC}"

    # Run test using cli.sh and capture output
    local output=$(cat "$snippet_file" | "$CLI_SCRIPT" --host "$HOST" "$command" 2>&1)

    # Check if output contains "Compilation failure"
    if echo "$output" | grep -q "Compilation failure"; then
        print_color "${RED}✗ FAILED: $snippet_name${NC}"
        FAILED_TESTS=$((FAILED_TESTS + 1))

        # Show error details
        print_color "${YELLOW}  Error output:${NC}"
        echo "$output" | sed 's/^/  /'
        echo ""
        return 1
    else
        print_color "${GREEN}✓ PASSED: $snippet_name${NC}"
        PASSED_TESTS=$((PASSED_TESTS + 1))
        return 0
    fi
}

# Print summary
print_summary() {
    echo ""
    echo "=========================================="
    print_color "${BLUE}Test Summary${NC}"
    echo "=========================================="
    printf "Total tests:  %s\n" "$TOTAL_TESTS"
    print_color "${GREEN}Passed:       $PASSED_TESTS${NC}"

    if [ $FAILED_TESTS -gt 0 ]; then
        print_color "${RED}Failed:       $FAILED_TESTS${NC}"
    else
        printf "Failed:       %s\n" "$FAILED_TESTS"
    fi

    echo "=========================================="

    if [ $FAILED_TESTS -eq 0 ]; then
        print_color "${GREEN}All tests passed!${NC}"
        return 0
    else
        print_color "${RED}Some tests failed${NC}"
        return 1
    fi
}

# Run all tests
run_tests() {
    {
        print_color "${BLUE}CXY Playground Test Runner${NC}"
        echo "=========================================="
        echo ""

        # Check if server is running
        if ! check_server; then
            return 1
        fi

        # Check if snippets directory exists
        if [ ! -d "$SNIPPETS_DIR" ]; then
            print_color "${RED}Error: Snippets directory not found at $SNIPPETS_DIR${NC}"
            return 1
        fi

        # Check if cli.sh exists
        if [ ! -x "$CLI_SCRIPT" ]; then
            print_color "${RED}Error: CLI script not found or not executable at $CLI_SCRIPT${NC}"
            return 1
        fi

        # Enumerate and test all .cxy files in snippets directory
        print_color "${BLUE}Discovering snippets...${NC}"
        local snippet_count=$(find "$SNIPPETS_DIR" -name "*.cxy" -type f | wc -l)
        printf "Found %s snippet(s)\n" "$snippet_count"
        echo ""

        if [ $snippet_count -eq 0 ]; then
            print_color "${YELLOW}Warning: No snippets found${NC}"
            return 0
        fi

        # Run tests on each snippet
        for snippet_file in "$SNIPPETS_DIR"/*.cxy; do
            if [ -f "$snippet_file" ]; then
                _runTest "$snippet_file"
            fi
        done

        # Print summary
        print_summary
        return $?
    } 2>&1 | tee -a "${SERVER_LOG}"
}

# Package test runner - orchestrates server lifecycle and test execution
package_run_tests() {
    # Set trap to ensure cleanup happens on exit, error, or interrupt
    trap cleanup_server EXIT INT TERM

    # Start server
    if ! start_server; then
        print_color "${RED}Failed to start server, aborting tests${NC}"
        cleanup_server
        return 1
    fi

    # Run tests
    TEST_EXIT_CODE=0
    run_tests || TEST_EXIT_CODE=$?

    # Cleanup server
    cleanup_server

    # Remove trap
    trap - EXIT INT TERM

    # Exit with test result
    return $TEST_EXIT_CODE
}

# Main execution (only when run directly, not sourced)
# Check if script is being sourced by seeing if $0 contains the script name
case "$0" in
    *test.sh)
        run_tests
        exit $?
        ;;
esac
