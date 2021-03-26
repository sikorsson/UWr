#include <stdio.h>
#include <stdlib.h>

#define __mmask(b1, b2) ( (((1 << (b2+1)) -1) >> (b1)) << (b1) )
#define __liftbit(x, a, b)            /* assume (b >= a) */ \
  ( ( ((x) & (1 << (a))) << (b - a) ) /* expose lift-bit */ \
  | ((__mmask(a + 1, b) & (x)) >> 1)  /* create leap-set */ \
  | ( (~__mmask(a, b)) & (x) )        /* clean bit-space */ )

#define __chopbits(w) (__liftbit(__liftbit(__liftbit(__liftbit(__liftbit(w, 5, 10), 4, 8), 3, 6), 2, 4), 1, 2))

typedef struct{
    char* ptr;
    int (*indexer)(int x, int y);
} MemDescriptor;

int indexerLined(int x, int y);
int indexerTiled(int x, int y);
int indexerZTiled(int x, int y);
MemDescriptor layToLined(MemDescriptor m);
MemDescriptor layToTiled(MemDescriptor m);
MemDescriptor layToZTiled (MemDescriptor m);
MemDescriptor createChequer();
void overwriteLines(MemDescriptor m);
void overwriteLine(MemDescriptor m);
void printChequer(MemDescriptor m, int (*indexer)(int, int));
short chopbits8(short x);
short zipbitsZ8(short x, short y);

int main()
{
    /*MemDescriptor z;
    z = createChequer();
    printChequer(z, &indexerLined);
    MemDescriptor y;
    y = layToTiled(z);
    printChequer(y, &indexerLined);
    MemDescriptor x;
    x = layToZTiled(y);
    printChequer(x, &indexerLined);
    overwriteLine(x);
    printChequer(x, x.indexer);*/
    printf("%d\n", chopbits8(255));
    printf("%d", zipbitsZ8(63, 63));
    return 0;
}

int indexerLined(int x, int y)
{
    return ((y<<6)|x);
}

int indexerTiled(int x, int y)
{
    return (((y>>3)<<9) | (x>>3)<<6 | ((y&7) << 3) | (x&7));
}

int indexerZTiled(int x, int y)
{
    return (__chopbits(x)| __chopbits(y)<<1);
}

MemDescriptor createChequer()
{
    MemDescriptor a;
    a.ptr = malloc(sizeof(char)*64*64);
    for(int y=0; y<64; y++)
    {
        for(int x=0; x<64; x++)
        {
            if((x/8)%2==(y/8)%2) a.ptr[indexerLined(x,y)] = 'B';
                else a.ptr[indexerLined(x,y)] = 'W';
        }
    }
    a.indexer = &indexerLined;
    return a;
}

MemDescriptor layToLined(MemDescriptor m)
{
    MemDescriptor a;
    a.ptr = malloc(sizeof(char)*64*64);
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<64; j++)
        {
                a.ptr[indexerLined(i,j)] = m.ptr[m.indexer(i,j)];
        }
    }
    a.indexer = &indexerLined;
    return a;
}

MemDescriptor layToTiled(MemDescriptor m)
{
    MemDescriptor a;
    a.ptr = malloc(sizeof(char)*64*64);
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<64; j++)
        {
                a.ptr[indexerTiled(i,j)] = m.ptr[m.indexer(i,j)];
        }
    }
    a.indexer = &indexerTiled;
    return a;
}

MemDescriptor layToZTiled (MemDescriptor m)
{
    MemDescriptor a;
    a.ptr = malloc(sizeof(char)*64*64);
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<64; j++)
        {
                a.ptr[indexerZTiled(i,j)] = m.ptr[m.indexer(i,j)];
        }
    }
    a.indexer = &indexerZTiled;
    return a;
}

void overwriteLines(MemDescriptor m)
{
    for(int y=0; y<8; y++)
    {
        for(int x=0; x<64; x++)
        {
                if(y%2==0) m.ptr[indexerLined(x, y)] = 'Q';
                    else m.ptr[indexerLined(x,y)] = 'X';
        }
    }
}

void overwriteLine(MemDescriptor m)
{
    for(int x=0; x<64; x++)
    {
            if(x<16) m.ptr[indexerLined(x, 0)] = 65+x;
            else if(x>47) m.ptr[indexerLined(x, 0)] = 49+x;
            else m.ptr[indexerLined(x, 0)] = '#';
    }
}

void printChequer(MemDescriptor m, int (*indexer)(int, int))
{
    for(int y=0; y<64; y++)
    {
        for(int x=0; x<64; x++)
        {
            printf("%c", m.ptr[indexer(x,y)]);
        }
        printf("\n");
    }
    printf("\n");
}

short chopbits8(short x)
{
    short a = (x|(x<<4))&0x0F0F;
    short b = (a|(a<<2))&0x3333;
    short c = (b|(b<<1))&0x5555;
    return c;
}

short zipbitsZ8(short x, short y)
{
        return (chopbits8(x) | chopbits8(y)<<1);
}

