#!/usr/bin/env bash
set -euo pipefail

if [ $# -ne 1 ]; then
  echo "Usage: $0 <day>"
  exit 1
fi

day=$(printf "%02d" "$1")
target="day${day}_test"
exe="build/${target}"

cmake -S . -B build
cmake --build build --target "$target"

"$exe"
