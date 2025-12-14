#include "day02.h"

#include <stdio.h>

#include "unity.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_part1_simple(void) {
    const char *input =
        "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";

    FILE *f = fmemopen((void *)input, strlen(input), "r");
    size_t count;
    Range *ranges = read_input(f, &count);
    fclose(f);

    long result = part1(ranges, count);

    TEST_ASSERT_EQUAL(1227775554, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_part1_simple);
    return UNITY_END();
}
