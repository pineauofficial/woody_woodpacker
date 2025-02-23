#include "woody.h"

off_t determine_file_size(int fd) {
    off_t size = lseek(fd, 0, SEEK_END);
    if (size == -1)
        return (-1);
    lseek(fd, 0, SEEK_SET);
    return (size);   
}

char *mapping(int fd, off_t file_size) {
    char *addr;

    addr = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED)
        return (NULL);
    return (addr);
}

