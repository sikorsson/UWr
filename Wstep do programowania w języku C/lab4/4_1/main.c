#include <stdio.h>
#include <stdlib.h>

#define __maskbit(x, b) (x & (1 << b))

#define __wipebit(x, b) (x & ~(1 << b))

#define __firebit(x, b) (x | (1 << b))

#define __flipbit(x, b) (x ^ (1 << b))

#define __copybit(x, b1, b2) ((b1<b2) ? ((__maskbit(x,b1) << (b2-b1)) | (__wipebit(x,b2))) : ((__maskbit(x,b1) >> (b1-b2)) | (__wipebit(x,b2))))

#define __swapbit(x, b1, b2) (__wipebit(__copybit(x, b1, b2), b1) | __wipebit(__copybit(x, b2, b1), b2))

int main()
{
    //printf("%d ", __maskbit(7,1));
    //printf("%d ", __wipebit(7,2));
    //printf("%d ", __firebit(7,0));
    //printf("%d ", __flipbit(7,2));
    //printf("%d ", __copybit(7,1,3));
    printf("%d ", __swapbit(34,5,3));
    return 0;
}
