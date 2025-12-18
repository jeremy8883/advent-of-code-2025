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

        data[len++] = strdup(line);
    }

    *count = len;
    return data;
}

long get_batteries(char* line) {
    size_t len = strlen(line) - 1; // exclude newline
    size_t first_index = 0;
    for (size_t i = 1; i < len - 1; i++) {
        char c = line[i];
        if (c > line[first_index])
            first_index = i;
    }
    size_t second_index = first_index + 1;
    for (size_t i = first_index + 2; i < len; i++) {
        char c = line[i];
        if (c > line[second_index])
            second_index = i;
    }

    char combination[3];
    snprintf(combination, sizeof combination, "%c%c", line[first_index], line[second_index]);
    return strtol(combination, NULL, 10);
}

long part1(char **lines, size_t count) {
    long sum = 0;
    for (size_t i = 0; i < count; i++) {
        char* line = lines[i];
        sum += get_batteries(line);
    }
    return sum;
}

long part2(char **lines, size_t count) {
    return 0;
}
