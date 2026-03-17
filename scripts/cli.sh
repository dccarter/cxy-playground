#!/bin/bash

# CXY Playground CLI Script
# Sends requests to the CXY playground server

set -e

# Default values
HOST="${CXY_SERVER_HOST:-0.0.0.0:8100}"
ARGS=""
COMMAND=""
SOURCE=""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Usage function
usage() {
    echo "Usage: $0 [OPTIONS] <command> [source_code]"
    echo ""
    echo "Commands:"
    echo "  build   - Compile the code"
    echo "  run     - Compile and execute the code"
    echo "  test    - Run as a test"
    echo ""
    echo "Arguments:"
    echo "  source_code  - Base64 encoded source code (optional, reads from stdin if not provided)"
    echo ""
    echo "Options:"
    echo "  --args ARGS  - Arguments to pass to the server"
    echo "  --host HOST  - Server host:port (default: $HOST)"
    echo "  --help, -h   - Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 build < myfile.cxy"
    echo "  $0 --args '--verbose' run"
    echo "  $0 build \$(cat myfile.cxy | base64 -w 0)"
    echo "  echo 'func main() { println(\"Hello\") }' | $0 run"
}

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --args)
            ARGS="$2"
            shift 2
            ;;
        --host)
            HOST="$2"
            shift 2
            ;;
        --help|-h)
            usage
            exit 0
            ;;
        build|run|test)
            COMMAND="$1"
            shift
            ;;
        *)
            if [[ -z "$COMMAND" ]]; then
                echo -e "${RED}Error: Unknown option '$1'${NC}" >&2
                usage
                exit 1
            else
                # This should be the source code
                SOURCE="$1"
                shift
            fi
            ;;
    esac
done

# Validate command
if [[ -z "$COMMAND" ]]; then
    echo -e "${RED}Error: Command is required${NC}" >&2
    usage
    exit 1
fi

if [[ ! "$COMMAND" =~ ^(build|run|test)$ ]]; then
    echo -e "${RED}Error: Invalid command '$COMMAND'${NC}" >&2
    usage
    exit 1
fi

# Get source code
if [[ -z "$SOURCE" ]]; then
    # Read from stdin and base64 encode
    echo -e "${YELLOW}Reading source code from stdin...${NC}" >&2
    SOURCE=$(cat | base64 -w 0 2>/dev/null || cat | base64)
else
    # Assume it's already base64 encoded, but validate
    if ! echo "$SOURCE" | base64 -d >/dev/null 2>&1; then
        echo -e "${YELLOW}Source doesn't appear to be base64 encoded, encoding it...${NC}" >&2
        SOURCE=$(echo "$SOURCE" | base64 -w 0 2>/dev/null || echo "$SOURCE" | base64)
    fi
fi

# Validate source code
if [[ -z "$SOURCE" ]]; then
    echo -e "${RED}Error: No source code provided${NC}" >&2
    exit 1
fi

# Create JSON payload
JSON_PAYLOAD=$(cat <<EOF
{
    "code": "$SOURCE",
    "args": "$ARGS"
}
EOF
)

# Make request to server
echo -e "${YELLOW}Sending $COMMAND request to $HOST...${NC}" >&2

RESPONSE=$(curl -s -X POST \
    -H "Content-Type: application/json" \
    -d "$JSON_PAYLOAD" \
    "http://$HOST/$COMMAND" 2>/dev/null)

CURL_EXIT_CODE=$?

if [[ $CURL_EXIT_CODE -ne 0 ]]; then
    echo -e "${RED}Error: Failed to connect to server at $HOST${NC}" >&2
    echo -e "${RED}Make sure the server is running${NC}" >&2
    exit 1
fi

# Check if response is valid JSON
if ! echo "$RESPONSE" | jq . >/dev/null 2>&1; then
    echo -e "${RED}Error: Invalid response from server${NC}" >&2
    echo "Response: $RESPONSE" >&2
    exit 1
fi

# Extract status
STATUS=$(echo "$RESPONSE" | jq -r '.status // 1')

# Extract and decode stdout
STDOUT_B64=$(echo "$RESPONSE" | jq -r '.stdout // ""')
if [[ -n "$STDOUT_B64" && "$STDOUT_B64" != "null" ]]; then
    STDOUT=$(echo "$STDOUT_B64" | base64 -d 2>/dev/null || echo "$STDOUT_B64")
    echo "$STDOUT"
fi

# Extract and decode stderr (to stderr)
STDERR_B64=$(echo "$RESPONSE" | jq -r '.stderr // ""')
if [[ -n "$STDERR_B64" && "$STDERR_B64" != "null" ]]; then
    STDERR=$(echo "$STDERR_B64" | base64 -d 2>/dev/null || echo "$STDERR_B64")
    echo -e "${RED}$STDERR${NC}" >&2
fi

# Exit with the status from the server
if [[ "$STATUS" != "0" ]]; then
    echo -e "${RED}Command failed with status $STATUS${NC}" >&2
    exit 1
else
    echo -e "${GREEN}Command completed successfully${NC}" >&2
fi
