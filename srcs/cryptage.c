#include "woody.h"

//C = M^e mod n
int public_cryptage(PublicKey *public_key, int message) {
   
    int resultat = 1;
    int i = public_key->e;
    while(i != 0)
    {
        resultat = (message * resultat) % public_key->n;
        i--;
    }
    printf("resultat = %d\n", resultat);
    return resultat;
}

//M = C^d mod n,
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

