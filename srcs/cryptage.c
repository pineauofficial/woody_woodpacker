#include "woody.h"

//C = M^e mod n
int public_cryptage(PublicKey *public_key, int message) {
   
    int resultat = 1;
    public_key->e = 7;
    public_key->n = 33;
    int i = public_key->e;
    while(i != 0)
    {
        resultat = (message * resultat) % public_key->n;
        i--;
    }
    printf("resultat public = %d\n", resultat);
    return resultat;
}

//M = C^d mod n
int private_decrytage(PrivateKey *private_key, int message) {
    
    int resultat = 1;
    int i = private_key->d;
    while(i != 0)
    {
        resultat = (message * resultat) % private_key->n;
        i--;
    }
    printf("resultat = %d\n", resultat);
    return resultat;
}

int *char_to_int(char *message, size_t length) {
    int size_total = 0;
    
    for (size_t i = 0; i < length; i++)
    {
        int val = (unsigned char)message[i];
        size_total += int_length(val);
    }
    
    int *number_message = malloc(sizeof(int) * size_total);
    if (!number_message) 
    {
        perror("Erreur d'allocation mémoire");
        return NULL;
    }
    
    int j = 0;
    for (size_t i = 0; i < length; i++) {
        int temp = (unsigned char)message[i];
        int digits[3] = {0}; 
        int digit_count = 0;
        
        if (temp == 0) 
            number_message[j++] = 0;
        else 
        {
            while (temp > 0) 
            {
                digits[digit_count++] = temp % 10;
                temp /= 10;
            }

            for (int k = digit_count - 1; k >= 0; k--)
                number_message[j++] = digits[k];
        }
    }
    
    return number_message;
}

int convert_message_to_int(PublicKey *public_key, PrivateKey *private_key, char *message, off_t file_size) {
    int *number_message = char_to_int(message, file_size);
    (void)private_key;
    (void)public_key;
    free(number_message);
    return 0;
}