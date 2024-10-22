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

void printstr(char *s) {
  for (size_t i = 0; i < strlen(s); i++){
    putchar(s[i]);
    usleep(4000);
  }
}

void banner(void) {
  char *col[7] = {YELLOW, CYAN, GREEN, RED, BLUE, MAGENTA, LIGHT_GRAY};
  srand(time(NULL));
  puts(col[rand() % 6]);
  cls();
  printstr(
    "▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧\n"
    "▧                                              ▧\n"
    "▧  Hola mi Amigos! Send me the string \"flag\"   ▧\n"
    "▧  and I will give you uno grande prize!!      ▧\n"
    "▧                                              ▧\n"
    "▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧\n\n$ ");
  char buf[0x10] = {0};
  read(0, buf, 6);
  !strncmp(buf, "flag", 4) ? read_flag() : error("Que??");
}

int main(void) {
  banner();
  return 0;
}

__attribute__((constructor))
void setup(void) {
  cls();
  setvbuf(stdin,  NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  alarm(0x1312);	
}
