#include "woody.h"

void error(char *str, int fd) {
    if (fd > 0)
        close(fd);
    if (str != NULL)
        perror(str);
}

void print_file(char *addr, off_t file_size) {

    for (off_t i = 0; i < file_size; i++)
    {
        printf("%02x ", (unsigned char)addr[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
}

void print_file_number(int fd, int *number_message) {
    for (int i = 0; i < determine_file_size(fd); i++)
        printf("%d", number_message[i]);
    printf("\n");
}

char **split(char *buffer) {

    char **tab = (char**)malloc(sizeof(char*) * (strlen(buffer) + 1));
    if (!tab)
        return NULL;

    int i = 0;
    int j = 0;
    int k = 0;
    while (buffer[i])
    {
        tab[j] = (char*)malloc(sizeof(char) * 2);
        if (!tab[j])
        {
            for (int x = 0; x < j; x++)
            free(tab[x]);
        free(tab);
        return NULL;
    }
    
    k = 0;
    tab[j][k] = buffer[i];
    tab[j][k+1] = '\0';
        j++;
        i++;
    }
    tab[j] = NULL;

    return tab;
}

void free_tab(char **tab) {
    int i;

    i = 0;
    if (!tab)
        return;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int int_length(int num) {
    int length = 0;

    if (num == 0)
        return 1;
    
    while (num > 0)
    {
        length++;
        num /= 10;
    }
    
    return length;
}