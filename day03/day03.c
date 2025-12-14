#include "day03.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_input(FILE *f, size_t *count) {
    if (!f) return NULL;

    size_t cap = 16;
    size_t len = 0;
    char **data = malloc(cap * sizeof *data);

    char line[128];
    while (fgets(line, sizeof line, f)) {
        if (len == cap) {
            cap *= 2;
            data = realloc(data, cap * sizeof *data);
        }

        data[len++] = line;
    }

    *count = len;
    return data;
}

char* part1(char **lines, size_t count) {
    return "0";
}

char* part2(char **lines, size_t count) {
    return "0";
}
