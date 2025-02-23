#include "woody.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
   
    int fd;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        error("open", -1);
        return (1);
    }

    off_t file_size = determine_file_size(fd);
    if(file_size < 0)
    {
        error("lseek", fd);
        return (1);
    }
    char *addr = mapping(fd, file_size);
    if (addr == NULL)
    {
        error("mmap", fd);
        return (1);
    }
  
    if (memcmp(addr, "\x7f" "ELF", 4) == 0) 
    {
        if (addr[EI_CLASS] == ELFCLASS64)
            printf("C'est un exécutable ELF 64 bits.\n");
        else 
            printf("File architecture not suported. x86_64 only\n");
    } 
    // print_file(addr, file_size);
    algo();
    if (munmap(addr, file_size) != 0)
        error("munmap", -1);
    close(fd);
}