#include "day02.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Range *read_input(FILE *f, size_t *count) {
    if (!f) return NULL;

    size_t cap = 16;
    size_t len = 0;
    Range *ranges = malloc(cap * sizeof *ranges);

    char line[8];
    while (fgets(line, sizeof line, f)) {
        Range m;
        sscanf(line, "%ld-%ld", &m.start, &m.end);

        if (len == cap) {
            cap *= 2;
            ranges = realloc(ranges, cap * sizeof *ranges);
        }

        ranges[len++] = m;
    }

    *count = len;
    return ranges;
}

long part1(Range *ranges, size_t count) {
    return 0;
}

long part2(Range *ranges, size_t count) {
    return 0;
}
