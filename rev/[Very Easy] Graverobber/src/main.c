#include <stdint.h>
#include <stdio.h>

#include <sys/stat.h>

// HTB{br34k1n9_d0wn_th3_sysc4ll5}
uint32_t parts[] = {
    U'H',
    U'T',
    U'B',
    U'{',
    U'b',
    U'r',
    U'3',
    U'4',
    U'k',
    U'1',
    U'n',
    U'9',
    U'_',
    U'd',
    U'0',
    U'w',
    U'n',
    U'_',
    U't',
    U'h',
    U'3',
    U'_',
    U's',
    U'y',
    U's',
    U'c',
    U'4',
    U'l',
    U'l',
    U'5',
    U'}',
    0,
};

#define N_PARTS sizeof(parts)/sizeof(parts[0])

int main() {
    char buf[(N_PARTS * 2) + 4] = { 0 };
    struct stat st;
    for (int i = 0; i < N_PARTS; i++) {
        buf[i * 2] = parts[i];
        buf[(i * 2) + 1] = '/';
        if (stat(buf, &st)) {
            puts("We took a wrong turning!");
            return 1;
        }
    }
    puts("We found the treasure! (I hope it's not cursed)");
}