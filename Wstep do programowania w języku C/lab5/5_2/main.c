#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROUND_UP_toPOT(x) \
    (x & (x-1)) == 0 ? x : \
    (x & (1 << 10)) ? 2048 : \
    (x & (1 << 9)) ? 1024 : \
    (x & (1 << 8)) ? 512 : \
    (x & (1 << 7)) ? 256 : \
    (x & (1 << 6)) ? 128 : \
    (x & (1 << 5)) ? 64 : \
    (x & (1 << 4)) ? 32 : \
    (x & (1 << 3)) ? 16 : \
    (x & (1 << 2)) ? 8 : \
    (x & (1 << 1)) ? 4 : 2

#define ROUND_UP_toMPOT(x, k) \
    (x < (1 << k))  ? (1 << k) : \
    (x==(((x >> k) << k))) ? x : \
    ((x >> k) << k) + (1 << k)

typedef struct {
    void* haxRef;
    void* natPtr;
    } RefBox;



RefBox allocatePOTMemAligned(int expBbSize, int log2unit ,int log2align)
{

}

int main()
{
    int expBbSize = 500;
    int log2unit = 2;
    int log2align = 8;

    int POTBbSize = ROUND_UP_toPOT(expBbSize);
    int log2POTBbSize = log2(POTBbSize);
    int log2POTUbSize = log2POTBbSize - log2unit;
    int unit = (1 << log2unit);
    int align = (1 << log2align);
    int waste = align -1;

    int usableBbSize = (1 << (log2POTUbSize + log2unit));
    int totalBbSize = POTBbSize + waste;

    void* natPtr = malloc(totalBbSize);
    void* haxPtr = (void*)(ROUND_UP_toMPOT((uintptr_t)natPtr, log2align));
    return 0;
}
