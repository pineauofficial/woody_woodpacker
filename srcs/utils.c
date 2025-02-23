#include "woody.h"

void error(char *str, int fd) {
    if (fd > 0)
        close(fd);
    if (str != NULL)
        perror(str);
}

void print_file(char *addr, off_t file_size) {
    // file_size = 16;
    for (off_t i = 0; i < file_size; i++)
    {
        printf("%02x ", (unsigned char)addr[i]); //affiche chaque octet en hexa
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
}
