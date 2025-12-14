#include <stdio.h>
#include <stdlib.h>
#include "day03.h"

int main(void) {
    size_t count;
    Range *ranges = read_input(stdin, &count);

    long result = part1(ranges, count);
    printf("Part 1: %ld\n", result);

    result = part2(ranges, count);
    printf("Part 2: %ld\n", result);

    return EXIT_SUCCESS;
}
