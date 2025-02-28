#include "woody.h"

/*Pour chiffrer un message, il suffit de connaître e et n. En revanche pour déchiffrer, il faut d et n.
Pour calculer d à l'aide de e et n, il faut trouver l'inverse modulaire de e modulo (p – 1)(q – 1),
ce que l'on ne sait pas faire sans connaître les entiers p et q, c'est-à-dire la décomposition de n en facteurs premiers. */

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
  
    print_file(addr, 16);
    if (memcmp(addr, "\x7f" "ELF", 4) == 0)
    {
        if (addr[EI_CLASS] == ELFCLASS64)
            printf("C'est un exécutable ELF 64 bits.\n");
        else
        {
            printf("File architecture not suported. x86_64 only\n");
            close(fd);
            return(1);
        }
    }
    else
    {
        printf("Ce n'est pas un fichier ELF.\n");
        close(fd);
        return(1);
    }

    int prime_one = 0;
    int prime_two = 0;
    while(1)
    {
        prime_one = prime_generator();
        printf("premier nombre premier = %d\n", prime_one);
        prime_two = prime_generator();
        printf("deuxieme nombre premier = %d\n", prime_two);
        if (prime_one == -1 || prime_two == -1)
            return 1;
        if(prime_one != prime_two)
            break;
    }

    PublicKey public_key;
    PrivateKey private_key;

    rsa(prime_one, prime_two, &public_key, &private_key);
    convert_message_to_int(&public_key, &private_key, addr, file_size);

    if (munmap(addr, file_size) != 0)
        error("munmap", -1);
    close(fd);
}