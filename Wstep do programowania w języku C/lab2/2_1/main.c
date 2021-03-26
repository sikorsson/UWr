#include <stdio.h>
#include <stdlib.h>

#if 0
#define TASK_CASE_B
#endif
#if 0
#define TASK_CASE_C
#endif
#if 1
#define TASK_CASE_D
#endif
#if 0
#define TASK_CASE_E
#endif


int main()
{
    #ifdef TASK_CASE_B
    #define pod_b 10
    printf("%d\n", pod_b);
    #endif

    #ifdef TASK_CASE_B
    #undef pod_b
    #define pod_b 20
    printf("%d\n", pod_b);
    #endif


    #ifdef TASK_CASE_C
    int T[]={6,9};
    int array_size;
    #define elements(x) (sizeof(x)/sizeof(x[0]))
    array_size=elements(T);
    printf("%d\n", array_size);
    #endif


    #ifdef TASK_CASE_D
    #define DECL_INIT(name, type, val) type name##_##type = val
    DECL_INIT(x, int, 7);
    printf("%d", x_int);
    #endif


    #ifdef TASK_CASE_E
    int revlog2(int y)
    {
        int z=1;
        for(int i=y-1; y>0; y--) z*=2;
        return z;
    }
    int x;
    scanf("%d", &x);
    int odp=revlog2(x);
    printf("%d", odp);
    #endif

    return 0;
}
