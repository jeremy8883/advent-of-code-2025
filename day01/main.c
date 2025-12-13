#include <stdio.h>
#include <stdlib.h>

int wrap(int n, int mod) {
    return ((n % mod) + mod) % mod;
}

int main(void) {
    FILE *f = fopen("day01/input.txt", "r");
    if (!f) {
        perror("Failed to open input.txt");
        return EXIT_FAILURE;
    }

    int pos = 50;
    int password = 0;

    char line[32];
    while (fgets(line, sizeof(line), f)) {
        char dir;
        int amount;

        sscanf(line, "%c%d", &dir, &amount);

        if (dir == 'L') {
            pos = wrap(pos - amount, 100);
        } else if (dir == 'R') {
            pos = wrap(pos + amount, 100);
        }
        printf("%c%i = %i\n", dir, amount, pos);

        if (pos == 0) {
            password += 1;
        }
    }

    printf("%d\n", password);

    return 0;
}
