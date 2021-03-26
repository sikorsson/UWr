#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char* ptr;
    int (*indexer)(int x, int y);
} MemDescriptor;

int indexerLined(int x, int y);
int indexerTiled(int x, int y);
MemDescriptor layToLined(MemDescriptor m);
MemDescriptor layToTiled(MemDescriptor m);
MemDescriptor createChequer();
void overwriteLines(MemDescriptor m);
void printChequer(MemDescriptor m, int (*indexer)(int, int));

int main()
{
    MemDescriptor z;
    z = createChequer();
    printChequer(z, &indexerLined);
    MemDescriptor y;
    y = layToTiled(z);
    printChequer(y, &indexerLined);
    overwriteLines(y);
    printChequer(y, y.indexer);
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

