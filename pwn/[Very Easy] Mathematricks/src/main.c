#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define RED           "\e[1;31m"
#define GREEN         "\e[1;32m"
#define YELLOW        "\e[1;33m"
#define BLUE          "\e[1;34m"
#define MAGENTA       "\e[1;35m"
#define CYAN          "\e[1;36m"
#define LIGHT_GRAY    "\e[1;37m"
#define RESET         "\e[0m"
#define SIZE 32

/*
* Compile a program with older libc:
 docker run -v "${PWD}:/mnt" -it debian:latest bash
 apt update; apt install -y gcc make vim gdb tmux && cd /mnt
*/

void error(char *msg) {
  printf("\n%s[-] %s%s\n", RED, msg, BLUE);
}

void cls() {
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
}

void read_flag() {
  char c;
  int fp = open("./flag.txt", O_RDONLY);
  if (fp < 0) {
    perror("\nError opening flag.txt, please contact an Administrator\n");
    exit(EXIT_FAILURE);
  }
  while ( read(fp, &c, 1) > 0 )
    fprintf(stdout, "%c", c);
  close(fp);
}

uint64_t read_num() { 
  char temp[32] = {0};
  read(0, temp, 31);
  return strtoul(temp, 0x0, 0);
}

void printstr(char *s) {
  for (size_t i = 0; i < strlen(s); i++){
    putchar(s[i]);
    usleep(2000);
  }
}

void banner(void) {
  cls();
  char *col[7] = {YELLOW, CYAN, GREEN, RED, BLUE, MAGENTA, LIGHT_GRAY};
  srand(time(NULL));
  puts(col[rand() % 6]);
  printstr("\t🎉 ~~ w3lC0m3 2 tH3 M4th3M4tR1kCs c0nt35t ~~ 🎉\n\n");
}

uint64_t menu() {
  printstr(""
  "\t\t\t■ ■ ■ ■ ■ ■ ■\n"
  "\t\t\t■           ■\n"
  "\t\t\t■ 1. Play   ■\n"
  "\t\t\t■ 2. Rules  ■\n"
  "\t\t\t■           ■\n"
  "\t\t\t■ ■ ■ ■ ■ ■ ■\n\n\t\t\t🥸 ");  
  
  return read_num();
}

void game() {
  printstr("\n\t\t🎉 ~~ Let the game begin! ~~ 🎉\n\n");
  printstr("\t\tQ1: 1 + 1 = ?\n\n\t\t> ");
  if (read_num() != 2) { 
    printstr("\n\t\t[!] Elementary school opens at 07:00 AM, don't miss it!\n\n");
    exit(1312);
  }
  printf("\n\t\t%s[+] THAT WAS AMAZING!\n\n%s", GREEN, BLUE);
  printstr("\t\tQ2: 2 - 1 = ?\n\n\t\t> ");
  if (read_num() != 1) { 
    printstr("\n\t\t[!] Elementary school opens at 07:00 AM, don't miss it!\n\n");
    exit(1312);
  }
  printf("\n\t\t%s[+] WE HAVE A MATHEMATICIAN AMONG US!\n\n%s", GREEN, CYAN);
  printstr("\t\tQ3: 1337 - 1337 = ?\n\n\t\t> ");
  if (read_num() != 0) { 
    printstr("\n\t\t[!] High school opens at 07:00 AM, don't miss it!\n\n");
    exit(1312);
  }
  printf("\n\t\t%s[+] GOD OF MATHS JUST ENTERED THE CHAT..\n\n%s", GREEN, BLUE);
  int64_t n1, n2;
  printstr("\t\tQ4: Enter 2 numbers n1, n2 where n1 > 0 and n2 > 0 and n1 + n2 < 0\n\n\t\tn1: ");
  n1 = read_num();
  printstr("\n\t\tn2: ");
  n2 = read_num();
  int32_t n3 = n1 + n2;
  if (n1 <= 0 || n2 <= 0) {
    printstr("\n\t\t[!] Hacking school opens at 13:37 AM, don't miss it!\n\n");
    exit(1312);    
  }
  (n3 < 0) ? read_flag() : printstr("\n\t\t[!] Hacking school opens at 13:37 AM, don't miss it!\n\n");
  exit(1312);
}

void rules() {
  printstr("\n"
    "\t\t\t■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■\n"
    "\t\t\t■                                                                     ■\n"
    "\t\t\t■  Solve the math questions to get the flag, some of them are tricky! ■\n"
    "\t\t\t■                                                                     ■\n"
    "\t\t\t■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■\n\n"
  );
}

int main(void) {
  banner();
  for (;;) {
    switch ( menu() ) {
      case 1:  game(); break;
      case 2:  rules(); break;
      default: printf("%s\n\t\t\t[???????????]\n\n", RED); exit(1312);
    }
  }
  return 0;
}

__attribute__((constructor))
void setup(void) {
  cls();
  setvbuf(stdin,  NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  alarm(0x1312);	
}
