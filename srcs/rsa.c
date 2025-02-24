#include "woody.h"

int least_common_multiple(int p, int q) {
    int greater = (p > q) ? p : q;
    int smallest = (p < q) ? p : q;
    for (int i = greater; ; i += greater)
    {
        if (i % smallest == 0)
            return i;
    }
}

int chose_coprime(int lcm, int minus) {
    int result = lcm;
    result = result - minus;
    while (result > 0)
    {
        if(is_prime(result) == 0)
        {
            if(lcm / result != 0)
                return result;
        }
        result--;
    }
    return -1;
}

int modulare_multiplicative_inverse(int lcm, int coprime) {
    int r1 = lcm;
    int r2 = coprime;
    int s1 = 1;
    int s2 = 0;
    int t1 = 0;
    int t2 = 1;
    int q, r, s, t;
    
    while (r2 != 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        s = s1 - q * s2;
        t = t1 - q * t2;
           
        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }

    if (r1 != 1)
        return -1;

    if (t1 < 0)
        t1 += lcm;

    printf("modulare inverse = %d\n", t1);
    return t1;

}

int rsa(int p, int q) {
    int lcm = least_common_multiple(p - 1, q - 1);
    printf("lcm = %d\n", lcm);
    int coprime = chose_coprime(lcm, 1);
    printf("coprime = %d\n", coprime);

    int modulare;
    while(1)
    {
        modulare = modulare_multiplicative_inverse(lcm, coprime);
        if (modulare != -1)
            break;
        coprime = chose_coprime(lcm, coprime - 1);
        printf("Nouveau coprime\n");
    }
    (void)modulare;
    //public key n = p*q ; e = coprime
    //private key n = p*q ; d = modulare 
    return 0;
}
