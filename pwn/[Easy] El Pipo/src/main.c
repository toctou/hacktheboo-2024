#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

/*
* Compile a program with older libc:
 docker run -v "${PWD}:/mnt" -it debian:latest bash
 apt update; apt install -y gcc make vim gdb tmux && cd /mnt
*/

void read_flag() {
  char c;
  int fp = open("./flag.txt", O_RDONLY);
  if (fp < 0) {
    perror("\nError opening flag.txt, please contact an Administrator\n");
    exit(EXIT_FAILURE);
  }
  while ( read(fp, &c, 1) > 0 )
    fprintf(stdout, "%c", c);
  fflush(stdout);
  close(fp);
}

int main(void) {
  char buf[0x20] = {0};
  uint8_t check = 1;
  read(0, buf, 0x40);
  check != 1 ? read_flag() : ({ fprintf(stdout, "Not scary enough.. Boo! :("); fflush(stdout);});
  return 0;
}

__attribute__((constructor))
void setup(void) {
  setvbuf(stdin,  NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  alarm(0x1312);	
}
