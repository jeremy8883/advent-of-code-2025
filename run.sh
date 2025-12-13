#!/usr/bin/env bash
set -euo pipefail

if [ $# -ne 1 ]; then
  echo "Usage: $0 <day>"
  exit 1
fi

day=$(printf "%02d" "$1")
target="day${day}"
exe="build/${target}"
input="day${day}/input.txt"

cmake --build build --target "$target"

if [ -f "$input" ]; then
  "$exe" < "$input"
else
  "$exe"
fi
