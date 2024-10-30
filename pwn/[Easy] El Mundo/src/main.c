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

void show_buffer() {
  printf("%s"
    "  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⣤⡤⠴⠖⠛⠛⠉⠉⠉⢉⣽⣷⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣤⠤⠴⠒⠚⠛⠛⠛⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡤⠶⠶⠛⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⡹⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⢀⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⣤⣤⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⣸⠃⠀⠀⠀⠀⠘⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣛⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠘⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡶⠬⣝⣶⣶⠖⠁⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⡿⠛⠉⣉⣭⢿⡛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⢿⡆⠸⣿⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⠀⠀⡞⡇⢹⠀⣷⠈⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⢸⣷⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠿⠿⠿⢿⡆⠀⢧⢱⣸⣧⣻⣇⢻⣿⡎⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣦⣿⣿⠀⣼⢀⣀⣼⠇⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⠋⠀⠠⣤⣀⠀⢻⡄⡟⢿⣿⡛⠉⠙⣞⣿⣇⢸⣿⣿⠿⢿⣁⣀⣇⣻⣿⣿⣿⣿⣿⣿⣿⠿⣦⣭⡭⣭⠏⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠈⢿⣦⠀⢣⢳⠀⣈⣙⣦⡀⢿⣽⣿⠾⠋⠁⣀⣴⣿⣿⠿⣿⣿⣿⣿⣿⣿⡿⣝⠶⣤⠙⢾⡅⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⠀⠀⠀⡄⢈⣿⡇⢸⡄⢣⢻⣿⠿⠛⣿⠁⣠⣤⣾⣟⣩⣴⣿⣿⣿⣿⣿⣿⣿⠻⣦⡻⣄⡀⣦⢈⣁⢹⡆⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⠀⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⣾⣃⣾⣿⣧⠾⠗⠋⢉⣀⣤⣴⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣿⣿⣿⢸⡆⢿⠿⣇⠀⠀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⠀⢸⡓⠲⢦⠤⠶⠶⠶⠶⡶⠖⠒⠛⢉⣉⣉⣠⣼⡶⠶⠿⠛⠉⣡⣾⠿⣫⣴⣿⠿⢿⣏⢉⣛⣿⣿⣿⣿⣿⠟⣿⣿⣿⣿⣿⣿⡇⠸⣆⣉⣠⡀⠀⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⠀⠀⣸⡷⠤⠼⠤⣤⣤⠤⠴⠷⠶⠟⠛⠛⠛⠋⠉⠀⠀⢀⣠⣶⡿⢋⣵⣿⣿⡟⢿⣶⡤⠽⠼⣿⣿⣿⣿⣿⡏⢀⣿⣿⣿⣿⣿⣿⡳⢤⣬⣽⣯⣤⣤⠀⠀⠀⠀\n"
    "  ⠀⠀⠀⠀⠀⠀⢀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣿⡿⣛⣵⣿⢿⣿⣤⣽⣿⠟⣛⣯⣽⣿⢻⣿⣿⣿⣿⣇⣼⣿⣿⣿⣿⣿⣿⣏⠛⢲⡔⠛⠉⠀⠀⠀⠀⣠\n"
    "  ⠀⠀⠀⠀⠀⣠⠟⠁⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣤⣶⣾⣿⣿⣿⣿⣯⣵⣿⣿⣿⣷⣾⢿⠿⣿⡿⣽⡇⢀⣼⣽⣿⣿⣿⣿⣿⡟⠙⣿⣿⣿⣿⢿⡟⢿⣇⠀⢧⠀⠀⠀⣀⡶⠋⠉\n"
    "  ⠀⠀⠀⣀⡾⠋⠀⠀⠀⠐⠒⠶⠶⠿⠿⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⡿⢍⣿⣋⣵⡿⢾⣀⣈⡽⠷⠞⠉⠉⠉⣿⣿⣿⣿⣿⣇⣼⣿⣿⠏⣿⣈⢷⡈⢿⣆⡘⢦⣀⡶⠋⢀⣴⣾\n"
    "  ⠀⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣾⠟⢛⣫⣴⣿⣿⣿⣯⣤⣾⡿⠟⠛⠳⣾⠫⠁⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠛⠋⢓⣼⣿⣿⣿⣿⣾⣏⠉⣴⡟⠀⣴⣿⣿⣿\n"
    "  ⣶⠟⠁⠀⠀⠀⠀⠀⣀⣤⣤⣶⣿⠿⠛⣋⣡⣴⣾⣿⣿⣿⣿⣿⣿⠉⠉⡽⠁⠀⠀⠀⠈⠂⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣧⢀⣴⣿⠃⢿⠟⠛⠛⠛⠻⢷⣼⣠⣾⣿⣿⣿⣿\n"
    "  ⠁⠀⣀⣠⣤⣶⡶⠿⠟⢋⣉⣡⡴⠶⠛⠉⠉⢹⣿⣿⣿⣿⠿⠿⢿⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⠀⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿\n"
    "  ⠾⠛⠛⢉⣉⣤⡶⠶⠟⠛⠉⠁⠀⠀⠀⠀⠀⠸⣿⣿⠋⠁⠀⠀⣼⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
    "  ⡴⠶⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡜⡆⠀⠀⠀⣏⠀⠀⣠⣤⣴⡶⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⢻⣿⣿⣿⣿⣿⣿⣿⡿⠟⠉⣩\n"
    "  ⡛⠛⠒⠒⠲⠶⠤⠤⠤⠴⠶⠒⠒⠒⠚⠛⠛⠉⣉⣧⡘⠀⠀⠀⠈⠙⠛⠿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⡿⢸⣿⣿⣿⣿⣿⡆⠘⣿⣿⣿⣿⣿⠟⠃⠀⣠⣾⣿\n"
    "  ⡇⠀⠀⣶⣶⣶⣶⣶⣦⣦⣤⣤⣤⣶⣶⠶⠶⠿⢛⣉⣷⡀⠀⠀⠀⠀⠀⣀⣀⣐⣤⣤⣤⣄⣀⣀⠀⠀⠀⠀⠀⣼⣿⣿⡟⣱⣿⣿⣿⣿⣿⣿⣧⠀⢿⣿⣿⣿⠋⠀⢀⣾⣿⣿⣿\n"
    "  ⣷⠀⠀⢿⣿⣍⣄⣀⣀⣀⣀⣠⣤⣤⣤⣶⣶⣾⣿⣿⣿⣿⡄⠀⠀⠀⢸⠟⠉⠛⠋⠉⠉⠉⠉⠉⠁⠀⠀⠀⢠⣿⡿⢋⣼⡟⠁⣿⣿⣿⣿⣿⣿⡀⢸⣿⣿⡇⠀⠀⣼⣿⣿⣿⡇\n"
    "  ⣿⡀⠀⢸⣿⣿⣤⣤⣤⣤⣤⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠀⠀⢡⡀⣠⣤⣤⣤⣤⣤⡴⠃⠀⠀⢀⡿⢋⣴⣿⣿⠁⠠⣿⣿⣿⠋⠉⠙⣇⢸⣿⣿⠀⠀⠀⣿⣿⣿⣿⣿\n"
    "  ⣿⡇⠀⢸⡛⣩⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠻⠿⠛⠛⠻⠿⠋⠀⠀⠀⢀⣾⣶⣿⣿⣿⡇⠀⠀⣿⣿⣿⠀⠀⠀⢻⠈⣿⣿⠀⠀⠀⣿⣿⣿⣿⣿\n"
    "  ⣿⡇⠀⠀⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⠟⠉⣿⠁⠀⠀⣿⣿⣿⣆⠀⠀⢸⡇⣿⣿⡆⠀⠀⣿⣿⣿⣿⠿\n"
    "  ⣿⣿⠀⠀⣿⠿⠿⠾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠈⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⡿⠋⠁⠀⢠⠏⠀⠀⠀⢻⣿⣿⣿⡄⠀⢸⣧⣿⣿⣧⠀⠀⢿⣿⣿⣿⣄\n"
    "  ⣿⣿⡀⠀⢻⣀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠈⢿⣦⣤⣤⣤⣤⣤⣶⣿⡟⠋⠀⠀⠀⠀⡞⠀⠀⠀⠀⢸⣿⣿⣿⣿⣦⣸⢹⣿⣿⠟⢧⠀⠀⢻⣿⣿⣿\n"
    "  ⣿⣿⡇⠀⢸⣿⣿⡏⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⢸⡟⢿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⡞⠀⢀⣀⣀⣀⣀⣿⣿⣿⣿⣿⣿⣾⣿⡏⠀⠈⣷⣄⠀⠙⣿⣿\n"
    "  ⣿⣿⡇⠀⢸⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⣿⠀⠀⢸⣧⡀⠉⠛⠋⠁⠀⠀⠀⠀⠀⢀⡞⠀⠀⣿⠀⠀⠀⣀⣁⣀⣀⣈⣉⣭⣽⣿⠁⠀⢸⣿⣿⣷⣦⣿⢿\n"
    "  ⣿⣿⡇⠀⢸⣿⣿⣇⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⢸⠀⠀⢸⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⢠⡞⠀⠀⠀⡏⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⢸⣿⣿⣿⣿⣿⣿\n"
    "  ⠛⠉⠉⠉⠉⠉⢁⣠⣴⣿⣿⣿⣿⠛⠿⣿⣿⣿⣿⠃⠀⠀⠀⣠⡿⠀⠀⢸⡿⠈⠻⣿⡿⠁⠀⠀⢠⡼⠋⠀⠀⠀⢀⠇⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⢀⡼⠛⠁⠀⣹⣿⣿\n"
    "  ⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠙⠿⢿⣤⣀⣀⡀⠀⠀⠀⠀⢸⡇⠀⠀⠉⠀⠀⣠⠞⠉⠀⠀⠀⣀⣠⠾⡄⠀⢸⣿⣿⣿⠟⣋⣡⣿⣿⣿⣿⠟⠁⠀⢀⣴⣾⣿⣿⡿\n"
    "  ⣴⣿⣿⣿⣿⣿⣿⡿⣋⡽⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠳⣦⣄⠀⠸⠃⠀⠀⢀⣴⢊⣀⣀⣠⠴⠖⠚⠉⠁⢠⠇⠠⠟⢫⣿⠿⣺⣷⣿⣿⣿⡿⠃⠀⠀⣰⣿⣿⡿⠛⠉⠀\n"
    "  ⣿⣿⣿⣿⣿⣿⣧⡞⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⢀⡴⠚⠋⠉⠉⠉⠉⠀⠀⠀⠀⢀⣴⠏⠀⠀⣠⣿⢣⣾⣿⣿⣿⣿⣿⠇⠀⠀⢸⣿⣿⠏⠀⠀⠀⠀\n"
    "  ⣿⣿⣿⣿⠟⣾⠿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠀⣰⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣾⣿⡟⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⣿⣿⡿⣤⣀⣀⣠⣾\n"
    "  ⣿⣿⣿⠟⣾⣿⠀⠹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡿⠁⠀⠀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⣿⣿⠀⣿⣿⣿⣿⣯\n"
    "  ⣿⣿⣿⢰⣿⣿⣷⡀⠱⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠁⠀⠀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⢹⣿⡄⣿⣿⣿⢿⣿\n"
    "  ⣿⣿⠋⣼⣿⢿⡀⢳⡄⠹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡞⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⢷⡄⠀⠈⣿⣿⣾⣿⡇⠀⠈\n"
    "  ⣿⠏⣼⣿⡏⠀⣷⡀⠹⡄⠘⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⢱⡄⠀⠈⠻⣿⣿⣿⡀⠀\n"
    "  ⡏⢸⣿⣿⡇⠀⠈⣇⠀⠑⠄⠈⢿⣓⠦⣀⠀⠀⠀⠀⠀⣸⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡞⠀⠀⠀⠀⣀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⢸⣿⣦⣀⡀⠙⣿⣿⣇⡀\n\n", MAGENTA); 
  printf("\e[4mStack frame layout\e[0m%s \n\n", MAGENTA);
  printf("|      .      | <- Higher addresses\n");
  printf("|      .      |\n");
  printf("|%s_____________%s|%s\n", BLUE, MAGENTA, BLUE);
  printf("|             | <- %d bytes\n", SIZE + 0x20);  
  printf("| Return addr |\n");
  printf("|%s_____________%s|%s\n", LIGHT_GRAY, BLUE, LIGHT_GRAY);
  printf("|             | <- %d bytes\n", SIZE + 0x18);  
  printf("|     RBP     |\n");
  printf("|%s_____________%s|%s\n", YELLOW, LIGHT_GRAY, YELLOW);
  printf("|             | <- %d bytes\n", SIZE + 0x10);  
  printf("| Local vars  |\n");
  printf("|%s_____________%s|%s\n", GREEN, YELLOW, GREEN);
  printf("|             | <- %d bytes\n", SIZE);  
  printf("|  Buffer[%d] |\n", SIZE-1);
  printf("|_____________|\n");
  printf("|      .      |\n");
  printf("|      .      |\n");
  printf("|_____________|\n");
  printf("|             |\n");
  printf("|  Buffer[0]  |\n");
  printf("|_____________| <- Lower addresses\n%s", CYAN);
}

void show_stack(unsigned long *stack) {
  printf(
    "\n\n%-19s|%-20s\n", "      [Addr]", "      [Value]\n"
    "-------------------+-------------------\n"
  );
  for (int16_t i = 0; i < 10; i++) {
    printf("0x%016lx | 0x%016lx", &stack[i], stack[i]);
    if (&stack[i] == stack)
      printf(" <- Start of buffer (You write here from right to left)");
    if (&stack[i] == ((unsigned long)stack + SIZE))
      printf(" <- Local Variables");
    if (&stack[i] == ((unsigned long)stack + SIZE + 0x8))
      printf(" <- Local Variables (nbytes read receives)");
    if (&stack[i] == ((unsigned long)stack + SIZE + 0x10))
      printf(" <- Saved rbp");
    if (&stack[i] == ((unsigned long)stack + SIZE + 0x18))
      printf(" <- Saved return address");
    puts("");
  }
  puts("");
}

void cls() {
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
}

void read_flag() {
  puts("🎉 Congratulations! 🎉\n\nYou finished your second challenge! Here is your reward:\n");
  char c;
  int fp = open("./flag.txt", O_RDONLY);
  fflush(stdin);
  fflush(stdout);
  if (fp < 0) {
    perror("\nError opening flag.txt, please contact an Administrator\n");
    exit(EXIT_FAILURE);
  }
  while ( read(fp, &c, 1) > 0 )
    fprintf(stdout, "%c", c);
  fflush(stdin);
  fflush(stdout);
  puts("");
  close(fp);
  exit(0x69);
}

int main(void) {
  ssize_t nbytes = 0xdeadbeef;
  char buf[SIZE] = {0};
  show_buffer();
  show_stack(buf);
  printf("[*] Overflow  the buffer.\n[*] Overwrite the 'Local Variables' with junk.\n[*] Overwrite the Saved RBP with junk.\n[*] Overwrite 'Return Address' with the address of 'read_flag() [%p].'\n\n> ", &read_flag);
  nbytes = read(0, buf, 0x100);
  if (nbytes < 56) {
    show_stack(buf);
    printf("%s[-] You need to add more than %lu bytes!%s\n", RED, nbytes, CYAN); 
  }
  else {
    show_stack(buf);
    printf("[!] You changed the return address!%s\n", CYAN);  
  }
  show_stack(buf);
  return 0;
}

__attribute__((constructor))
void setup(void) {
  cls();
  setvbuf(stdin,  NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  alarm(0x6969);  
}
