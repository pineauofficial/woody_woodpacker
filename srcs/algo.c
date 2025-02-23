#include "woody.h"

// void hexaToDeci(char *buffer) {

// }

void algo() {
    unsigned char buffer[32];
    ssize_t result = ft_random(buffer, sizeof(buffer));
    if (result == -1)
    {
        printf("PROBLEME\n");
    }
    else
    {
        // printf("buffer : %s\n", buffer);
        print_file((char*)buffer, strlen((char*)buffer));
        printf("result : %ld\n", result);
    }
}