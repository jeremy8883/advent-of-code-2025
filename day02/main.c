#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long start;
    long end;
} Range;

Range *read_input(size_t *count) {
    FILE *f = stdin;
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

    fclose(f);
    *count = len;
    return ranges;
}


int wrap(int n, int mod) {
    return ((n % mod) + mod) % mod;
}

void part1(Range *ranges, size_t count) {

}

void part2(Range *ranges, size_t count) {

}

int main(void) {
    size_t count;
    Range *ranges = read_input(&count);
    if (!ranges) return EXIT_FAILURE;

    part1(ranges, count);
    part2(ranges, count);

    return EXIT_SUCCESS;
}
