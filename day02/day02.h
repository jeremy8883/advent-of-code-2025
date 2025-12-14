#ifndef ADVENT_OF_CODE_2025_MAIN_H
#define ADVENT_OF_CODE_2025_MAIN_H
#include <stdio.h>

typedef struct {
    long start;
    long end;
} Range;

Range *read_input(FILE *f, size_t *count);
long part1(Range *ranges, size_t count);
long part2(Range *ranges, size_t count);

#endif //ADVENT_OF_CODE_2025_MAIN_H
