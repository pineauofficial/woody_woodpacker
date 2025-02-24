#include "woody.h"

void convert_and_fill(char* str, int *tab) {
    int i = 0;
    while (*str)
    {
        tab[i] = (unsigned char)*str;
        str++;
        i++;
    }
}

int generator(int *tab) {
    int i = 0;
    while(tab[i])
        i++;
    if (i < 2)
        return -1;
    int resultat = 0;
    while(i != 0)
    {
        resultat += tab[i];
        i--;
    }
    return resultat;
}

int is_prime(int n) {

    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 1;
    }

    return 0;
}

int prime_generator() {
    char buffer[8];
    ssize_t result = ft_random(buffer, sizeof(buffer));
    if (result == -1)
        printf("PROBLEME\n");

    char **tab = split(buffer);
 
    char tmp[256];
    int i = 0;
    while(tab[i])
    {
        strcat(tmp, tab[i]);
        i++;
    }

    int tab_number[strlen(tmp)];
    convert_and_fill(tmp, tab_number);

    int return_value = -1;
    while(1)
    {
        return_value = generator(tab_number);
        if (return_value != -1 && is_prime(return_value) == 0 )
            break;
    }
    printf("return_value = %d\n", return_value);
    free_tab(tab);
    return return_value;
}