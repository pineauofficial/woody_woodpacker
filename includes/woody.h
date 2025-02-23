#ifndef WOODY_H
# define WOODY_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define EI_CLASS 4 //octet dans le header ELF qui def 32 bits ou 64 bits
#define ELFCLASS64 2 //fichier ELF 64 bits

/*mapping.c*/
off_t determine_file_size(int fd);
char *mapping(int fd, off_t file_size);

/*main.c*/

/*utils.c*/
void error(char *str, int fd);
void print_file(char *addr, off_t file_size);

/*algo.c*/
void algo();

/*ft_random.s*/
extern ssize_t ft_random(void *buf, size_t buflen);
extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);
extern int ft_strcmp( const char * first, const char * second );

#endif