#!/usr/bin/env bash
set -euo pipefail

if [ $# -ne 1 ]; then
  echo "Usage: $0 <day>"
  exit 1
fi

day=$(printf "%02d" "$1")

mkdir "day${day}"
cp template/day.c "day${day}/day${day}.c"
cp template/day.h "day${day}/day${day}.h"
cp template/day_test.c "day${day}/day${day}_test.c"
cp template/main.c "day${day}/main.c"

for file in "day${day}/day${day}.c" "day${day}/day${day}.h" "day${day}/day${day}_test.c" "day${day}/main.c"; do
  sed -i "s/#DAY#/${day}/g" "$file"
done
touch "day${day}/input.txt"
