#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char dir;
    int amount;
} Instruction;

enum {
    WRAP_POS = 100,
    START_POS = 50,
};

Instruction *read_instructions(size_t *count) {
    FILE *f = stdin;
    if (!f) return NULL;

    size_t cap = 16;
    size_t len = 0;
    Instruction *instructions = malloc(cap * sizeof *instructions);

    char line[8];
    while (fgets(line, sizeof line, f)) {
        Instruction m;
        sscanf(line, "%c%d", &m.dir, &m.amount);

        if (len == cap) {
            cap *= 2;
            instructions = realloc(instructions, cap * sizeof *instructions);
        }

        instructions[len++] = m;
    }

    fclose(f);
    *count = len;
    return instructions;
}


int wrap(int n, int mod) {
    return ((n % mod) + mod) % mod;
}

void part1(Instruction *instructions, size_t count) {
    int pos = START_POS;
    int password = 0;

    for (size_t i = 0; i < count; i++) {
        Instruction m = instructions[i];

        if (m.dir == 'L') {
            pos = wrap(pos - m.amount, WRAP_POS);
        } else if (m.dir == 'R') {
            pos = wrap(pos + m.amount, WRAP_POS);
        }

        if (pos == 0) {
            password += 1;
        }
    }

    printf("%d\n", password);
}

void part2(Instruction *instructions, size_t count) {
    int pos = START_POS;
    int password = 0;

    for (size_t i = 0; i < count; i++) {
        Instruction m = instructions[i];
        int new_pos;

        if (m.dir == 'L') {
            new_pos = pos - m.amount;
        } else if (m.dir == 'R') {
            new_pos = pos + m.amount;
        }
        if (new_pos < 0) {
            password += (pos == 0 ? 0 : 1) + (-new_pos / WRAP_POS);
        } else if (new_pos > 0) {
            password += new_pos / WRAP_POS;
        } else { // is zero
            password += 1;
        }
        pos = wrap(new_pos, WRAP_POS);
    }

    printf("%d\n", password);
}

int main(void) {
    size_t count;
    Instruction *instructions = read_instructions(&count);
    if (!instructions) return EXIT_FAILURE;

    part1(instructions, count);
    part2(instructions, count);

    return 0;
}
