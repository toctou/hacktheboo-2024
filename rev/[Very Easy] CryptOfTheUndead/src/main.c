#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "chacha.h"

int ends_with(const char* string, const char* suffix) {
    size_t s_len = strlen(string);
    size_t suf_len = strlen(suffix);
    if (suf_len > s_len) return 0;
    return strncmp(string + s_len - suf_len, suffix, suf_len) == 0;
}

int read_file(const char* path, size_t* out_len, char** out_buf) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) return fd;
    size_t amnt_read = 0;
    size_t buf_sz = 1024;
    char* buf = malloc(buf_sz);
    while (1) {
        ssize_t res;
        if ((res = read(fd, buf + amnt_read, buf_sz - amnt_read)) < 0) {
            close(fd);
            free(buf);
            return res;
        }
        amnt_read += res;
        if (res == 0) {
            close(fd);
            *out_buf = buf;
            *out_len = amnt_read;
            return 0;
        }
        if (!(buf = realloc(buf, buf_sz + 1024))) {
            close(fd);
            return 1;
        }
        buf_sz += 1024;
    }
}

void encrypt_buf(char* buffer, size_t buflen, uint8_t* key) {
    struct chacha20_context ctx;
    uint8_t nonce[12] = { 0 };
    chacha20_init_context(&ctx, key, nonce, 0);
    chacha20_xor(&ctx, buffer, buflen);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s file_to_encrypt\n", (argc > 0) ? argv[0] : "crypt");
        return 1;
    }
    const char* file = argv[1];
    if (ends_with(file, ".undead")) {
        puts("error: that which is undead may not be encrypted");
        return 2;
    }
    size_t new_filename_len = strlen(file) + sizeof(".undead") + 1;
    char* new_filename = malloc(new_filename_len);
    strncpy(new_filename, file, new_filename_len);
    strncat(new_filename, ".undead", new_filename_len);
    char* filebuf;
    size_t filelen;
    if (read_file(file, &filelen, &filebuf)) {
        perror("error reading file");
        return 3;
    }

    encrypt_buf(filebuf, filelen, "BRAAAAAAAAAAAAAAAAAAAAAAAAAINS!!");
    if (rename(file, new_filename)) {
        perror("error renaming file");
        return 4;
    }
    int fd = open(new_filename, O_WRONLY | O_TRUNC);
    if (fd < 0) {
        perror("error opening new file");
        return 5;
    }
    write(fd, filebuf, filelen);
    close(fd);
    puts("successfully zombified your file!");
    return 0;
}