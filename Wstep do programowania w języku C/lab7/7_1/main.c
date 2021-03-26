#include <stdio.h>
#include <stdlib.h>
#define memberoff__(T, m) ((char*)&((T*)1)->m-(char*)(T*)1)
#define OFFSET(T, m)  (&((T *)0)->m)

typedef struct{
        char a;
        char b;
        long c;
        long d;
       } lista;

void tidyMemkeeping()
{
    int *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
    n1=malloc(1);
    if(n1==NULL) goto ending;

    n2=malloc(1);
    if(n2==NULL) goto cl2;

    n3=malloc(1);
    if(n3==NULL) goto cl3;

    n4=malloc(1);
    if(n4==NULL) goto cl4;

    n5=malloc(1);
    if(n5==NULL) goto cl5;

    n6=malloc(1);
    if(n6==NULL) goto cl6;

    n7=malloc(1);
    if(n7==NULL) goto cl7;

    n8=malloc(1);
    if(n8==NULL) goto cl8;

    free(n8);
    cl8: free(n7);
    cl7: free(n6);
    cl6: free(n5);
    cl5: free(n4);
    cl4: free(n3);
    cl3: free(n2);
    cl2: free(n1);
    ending:
    return;
}

typedef struct Box{
    int* a;
}box;

int isValid(box* b)
{
    if(b->a == &(b->a)) return 1;
    else return 0;
}

int main()
{
    box x;
    tidyMemkeeping();
    printf("%d\n", memberoff__(lista, d));
    printf("%d\n", OFFSET(lista, d));
    printf("%d", isValid(&x));
    return 0;
}
