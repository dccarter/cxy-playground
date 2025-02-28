#!/usr/bin/bash
CODE=$(cat - | base64 -w 0)
ACTION="build"
ARGS=""
HOST="0.0.0.0:8100"

[[ $# -gt 0 ]] && {
  ACTION="$1"
  shift
}
[[ $# -gt 0 ]] && [[ "$1" == "--" ]] && {
  shift
  ARGS="$@"
}
REQUEST="{\"code\": \"${CODE}\", \"args\": \"${ARGS}\"}"
curl -s -d "${REQUEST}" -H "Accept: application/json" ${HOST}/${ACTION}