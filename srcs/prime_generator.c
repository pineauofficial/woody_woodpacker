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

int generator(int *tab, int len) {
    int i = 0;
    int resultat = 0;
    while(i < len)
    {
        resultat += tab[i];
        i++;
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

    return 0;//prime
}

int* generate_number_array(char* buffer, int* array_size) {

    char **tab = split(buffer);
    

    char tmp[256] = {0};
    int i = 0;
    while(tab[i]) {
        strcat(tmp, tab[i]);
        i++;
    }
    
    int length = strlen(tmp);
    int* tab_number = malloc(length * sizeof(int));
    if (!tab_number) {
        free_tab(tab);
        return NULL;
    }

    convert_and_fill(tmp, tab_number);

    *array_size = length;

    free_tab(tab);
    
    return tab_number;
}

int prime_generator() {
    char buffer[16] = {0};//arbitraire
    int return_value = -1;
    int array_size = 0;
    int* tab_number = NULL;
    
    ssize_t result = ft_random(buffer, sizeof(buffer));
    if (result == -1) {
        printf("PROBLEME\n");
        return -1;
    }
    buffer[sizeof(buffer) - 1] = '\0';
    
    tab_number = generate_number_array(buffer, &array_size);
    if (!tab_number) return -1;
    
    int attempts = 0;
    int MAX_ATTEMPTS = 100;//arbitraire 
    
    while(attempts < MAX_ATTEMPTS) 
    {
        return_value = generator(tab_number, array_size);
        
        if (return_value != -1 && is_prime(return_value) == 0 && return_value > 0 && return_value < 75000)//arbitraire 
            break;
        
        free(tab_number);
        
        result = ft_random(buffer, sizeof(buffer));
        if (result == -1) {
            printf("PROBLEME\n");
            return -1;
        }
        buffer[sizeof(buffer) - 1] = '\0';

        tab_number = generate_number_array(buffer, &array_size);
        if (!tab_number) return -1;
        
        attempts++;
    }
    
    printf("return_value = %d\n", return_value);
    free(tab_number);
    
    return return_value;
}