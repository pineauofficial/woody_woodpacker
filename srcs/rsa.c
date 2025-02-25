#include "woody.h"

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

PublicKey create_public_key(int p, int q, int e) {
    PublicKey public_key;
    public_key.n = p * q;
    public_key.e = e;
    return public_key;
}

PrivateKey create_private_key(int p, int q, int d) {
    PrivateKey private_key;
    private_key.n = p * q;
    private_key.d = d;
    return private_key;
}

int chose_coprime(int lcm, int start) {
    if (start < 3) start = 3;
    
    if (start % 2 == 0) start++;
    
    for (int i = start; i < lcm; i += 2) 
    {
        if (gcd(i, lcm) == 1)
            return i;
    }
    return -1;
}

int chose_coprime2(int lcm, int start) {
    start = lcm - 2;

    if(start % 2 == 0) start--;
    for (int i = start; i > 3; i -= 2)
    {
        if(gcd(i, lcm) == 1)
            return i;
    }
    return -1;
}

int least_common_multiple(int p, int q) {

    long long product = (long long)p * q;
    int g = gcd(p, q);
    return (int)(product / g);
}

int gcd(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int rsa(int p, int q, PublicKey *public_key, PrivateKey *private_key) {

    int lcm = least_common_multiple(p - 1, q - 1);
    printf("lcm = %d\n", lcm);
    
    if (lcm <= 0)
        return -1;
    
    int coprime = chose_coprime2(lcm, 3);
    if (coprime == -1)
        return -1;

    printf("coprime = %d\n", coprime);
    
    int modulare = modulare_multiplicative_inverse(lcm, coprime);
    if (modulare == -1)
        return -1;
    
    *public_key = create_public_key(p, q, coprime);
    *private_key = create_private_key(p, q, modulare);
    
    return 0;
}