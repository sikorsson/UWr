#include <stdio.h>
#include <stdlib.h>

#define ROUND_DN_toPOT(x) \
    (x & (1 << 3)) ? 8 : \
    (x & (1 << 2)) ? 4 : \
    (x & (1 << 1)) ? 2 : 1

#define ROUND_UP_toPOT(x) \
    (x & (x-1)) == 0 ? x : \
    (x & (1 << 3)) ? 16 : \
    (x & (1 << 2)) ? 8 : \
    (x & (1 << 1)) ? 4 : 2

#define ROUND_DN_toMPOT(x, k) ((x >> k) << k)

#define ROUND_UP_toMPOT(x, k) \
    (x < (1 << k))  ? (1 << k) : \
    (x==(((x >> k) << k))) ? x : \
    ((x >> k) << k) + (1 << k)

int main()
{
    for(int i=0;i<20;i++) printf("%d %d \n", i, ROUND_UP_toMPOT(i, 3));
    return 0;
}
