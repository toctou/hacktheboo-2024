#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    struct ListNode* next;
    char c;
};

#define LAST_ENTRY(chr) (struct ListNode){ .next = NULL, .c = chr }
#define ENTRY(chr, succ) (struct ListNode){ .next = &succ, .c = chr }

#include "flag.inc"

#if 0
void debug() {
    struct ListNode* cur = &part1;
    do {
        printf("%p, ", cur);
        cur = cur->next;
    } while (cur);
    cur = &part2;
    puts("\npart 2:");
    do {
        printf("%p, ", cur);
        cur = cur->next;
    } while (cur);
    puts("");
}
#endif

int main() {
#if 0
    debug();
#endif
    char buf[64];
    struct ListNode* cur = &part1;
    printf("The cultists look expectantly to you - who will you link hands with? ");
    fgets(buf, sizeof(buf), stdin);
    char* nl;
    if (nl = strchr(buf, '\n')) *nl = 0;
    struct ListNode *left, *right;
    if (sscanf(buf, "%p %p", &left, &right) != 2) {
        puts("You fail to grasp their hands - they look at you with suspicious...");
        return 1;
    }
    left->next = right;
    do {
        printf("%c", cur->c);
        cur = cur->next;
    } while (cur);
    putchar('\n');
    return 0;
}