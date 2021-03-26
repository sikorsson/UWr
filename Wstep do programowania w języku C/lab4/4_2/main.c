#include <stdio.h>
#include <stdlib.h>

#define __maskbit(x, b) (x & (1 << b))

#define __liftbit(x, b, k) (__maskbit(x, b)<<k) | (((((1<<k)-1)<<b+1) & x)>>1) | (~((((1<<k)-1)<<b+1) | __maskbit(x, b))& x)

int main()
{
    printf("%d ", __liftbit(21,2,2));
    return 0;
}
