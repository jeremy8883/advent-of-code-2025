#include "day#DAY#.h"

#include <stdio.h>

#include "unity.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_part1(void) {
    const char *input =
        "";

    FILE *f = fmemopen((void *)input, strlen(input), "r");
    size_t count;
    char **lines = read_input(f, &count);
    fclose(f);

    char* result = part1(lines, count);

    TEST_ASSERT_EQUAL_STRING("0", result);
}

void test_part2(void) {
    const char *input =
        "";

    FILE *f = fmemopen((void *)input, strlen(input), "r");
    size_t count;
    char **lines = read_input(f, &count);
    fclose(f);

    char* result = part2(lines, count);

    TEST_ASSERT_EQUAL_STRING("0", result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_part1);
    RUN_TEST(test_part2);
    return UNITY_END();
}
