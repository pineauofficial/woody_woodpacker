#include "woody.h"

int least_common_multiple(int p, int q) {
    p = 60;
    q = 52;
    int greater = (p > q) ? p : q;
    int smallest = (p < q) ? p : q;
    for (int i = greater; ; i += greater)
    {
        if (i % smallest == 0)
            return i;
    }
}

int rsa(int p, int q) {
    int lcm = least_common_multiple(p - 1, q - 1);
    printf("lcm = %d\n", lcm);
    return 0;
}
