#include <stdio.h>
#include <stdlib.h>


typedef unsigned char byte;
typedef struct _Box_{
    long l;
    short s;
    byte b1;
    byte b0;

} Box;

void printCPU_Bitness()
{
    printf("[CPU]Bitness: %d-bit\n", 8*sizeof(void*));
    return;
}

void printCPU_Endianness()
{
    /*long n = 1;
    byte *b = (byte*)&n;
    if (*b  )
        printf("[CPU]Endiannes: little-endian");
    else
        printf("[CPU]Endiannes: big-endian");*/
    union {
        long n;
        byte b[sizeof(long)];
    } x;
    x.n = 1;
    if(x.b[0]) printf("little-endian");
    else printf("big-endian");
    return;
}

int main()
{
    printf("sizeof(Box) = %d\n", sizeof(Box));
    printCPU_Bitness();
    printCPU_Endianness();
    return 0;
}
