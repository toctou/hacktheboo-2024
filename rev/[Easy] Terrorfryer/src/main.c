#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void fryer(char* s) {
    static int init = 0;
    static unsigned int seed;
    if (!init) {
        seed = 0x13377331;
        init = 1;
    }
    size_t len = strlen(s);
    if (!len) return;
    for (size_t i = 0; i < len - 1; i++) {
        int j = rand_r(&seed);
        j = j % (len - i) + i;
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// HTB{4_truly_t3rr0r_fry1ng_funct10n_9b3ab6360f11}
const char desired[] = "1_n3}f3br9Ty{_6_rHnf01fg_14rlbtB60tuarun0c_tr1y3";

int main() {
    char buffer[64];
    char* nl;
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Please enter your recipe for frying: ");
    fgets(buffer, sizeof(buffer), stdin);
    if (nl = strchr(buffer, '\n')) {
        *nl = 0;
    }
    fryer(buffer);
    printf(
        "got:      `%s`\n"
        "expected: `%s`\n", buffer, desired);
    if (strcmp(desired, buffer)) {
        puts("This recipe isn't right :(");
    } else {
        puts("Correct recipe - enjoy your meal!");
    }
}