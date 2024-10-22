#include <stdint.h>
#include <stdio.h>
#include <string.h>

// HTB{un0bfu5c4t3d_5tr1ng5}
uint32_t parts[] = {
    U'H',
    U'T',
    U'B',
    U'{',
    U'u',
    U'n',
    U'0',
    U'b',
    U'f',
    U'u',
    U'5',
    U'c',
    U'4',
    U't',
    U'3',
    U'd',
    U'_',
    U'5',
    U't',
    U'r',
    U'1',
    U'n',
    U'g',
    U'5',
    U'}',
    0,
};
#define N_PARTS sizeof(parts)/sizeof(parts[0])

int main() {
    char buf[128];
    char flagbuf[N_PARTS] = { 0 };
    puts("Welcome to the \x1b[1;3mSPOOKIEST\x1b[0m party of the year!");
    printf("Before we let you in, you'll need to give us the password: ");
    fgets(buf, sizeof(buf), stdin);
    char* nl;
    if (nl = strchr(buf, '\n')) *nl = 0;
    if (strcmp(buf, "s3cr3t_p455_f0r_gh05t5_4nd_gh0ul5") == 0) {
        puts("Welcome inside!");
        for (int i = 0; i < N_PARTS; i++) {
            flagbuf[i] = parts[i];
        }
        puts(flagbuf);
    } else {
        puts("You're not a real ghost; clear off!");
    }
}