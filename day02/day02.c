#include "day02.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Range *read_input(FILE *f, size_t *count) {
    if (!f) return NULL;

    size_t cap = 16;
    size_t len = 0;
    Range *ranges = malloc(cap * sizeof *ranges);
    if (!ranges) return NULL;

    long start, end;

    while (fscanf(f, "%ld-%ld,", &start, &end) == 2) {
        if (len == cap) {
            cap *= 2;
            Range *tmp = realloc(ranges, cap * sizeof *ranges);
            if (!tmp) {
                free(ranges);
                return NULL;
            }
            ranges = tmp;
        }

        ranges[len++] = (Range){ .start = start, .end = end };
    }

    *count = len;
    return ranges;
}

bool is_invalid(long val) {
    char str_val[32];
    sprintf(str_val, "%ld", val);
    size_t len = strlen(str_val);
    if (len % 2 == 1) {
        return false;
    }

    int mid = len / 2;
    char* left = strndup(str_val, mid);
    char* right = strdup(str_val + mid);

    return strcmp(left, right) == 0;
}

long part1(Range *ranges, size_t count) {
    long invalid_sum = 0;
    for (size_t i = 0; i < count; i++) {
        Range r = ranges[i];

        for (size_t i = r.start; i <= r.end; i++) {
            if (is_invalid(i)) {
                invalid_sum += i;
            }
        }
    }
    return invalid_sum;
}

long part2(Range *ranges, size_t count) {
    return 0;
}
