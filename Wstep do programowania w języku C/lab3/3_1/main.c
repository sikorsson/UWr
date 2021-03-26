#include <stdio.h>
#include <stdlib.h>

#if 0
#define TASK_CASE_A
#endif
#if 0
#define TASK_CASE_B
#endif
#if 0
#define TASK_CASE_C
#endif
#if 1
#define TASK_CASE_D
#endif


int main()
{
    #ifdef TASK_CASE_A
    #define MAXVAL_U32 ~0U
    printf("%llx\n", MAXVAL_U32);
    #define MAXVAL_U64 ~0UL
    printf("%llx\n", MAXVAL_U64);
    #endif // TASK_CASE_A


    #ifdef TASK_CASE_B
    #define BITWORD_8(b7,b6,b5,b4,b3,b2,b1,b0) ((b7<<7)|(b6<<6)|(b5<<5)|(b4<<4)|(b3<<3)|(b2<<2)|(b1<<1)|(b0<<0))
    int x=BITWORD_8(1,1,1,1,1,1,1,1);
    printf("%d\n", x);
    #endif // TASK_CASE_B


    #ifdef TASK_CASE_C
    #define MERGE_4BYTES(by3,by2,by1,by0) ((by3<<24)|(by2<<16)|(by1<<8)|(by0<<0))
    int y=MERGE_4BYTES(1,1,1,1);
    printf("%d\n", y);
    #endif // TASK_CASE_C


    #ifdef TASK_CASE_D
        #ifdef NDEBUG
            int divInteger(int N, int D)
        #else
            long divInteger(int N, int D)
        #endif
    {
        #ifdef NDEBUG
            return (N/D);
        #else
            return ((long)(N%D)<<32|(N/D));
        #endif
    }
    int wynik=divInteger(8,2);
    printf("%d",wynik);
    #endif // TASK_CASE_D
    return 0;
}
