#include <stdio.h>
#include <stdlib.h>

#define PRINT_DEC_VALUE(x) printf("dec-value of '%s' = %d", #x, x);
#define PRINT_HEX_VALUE(x) printf("hex-value of '%s' = %x", #x, x);
#define CODE_STAMP() fprintf(stderr, "file[%s] line[%d] func[%s]", __FILE__, __LINE__,__FUNCTION__);

int licz=0;

void getLog2(int x)
{
    int b;
    b=x%2;
    x=x-b;
    while(x>=2)
    {
        x=x/2;
        licz=licz+1;
    }
    return 0;
}

void isPOT(int y)
{
    if(y%2!=0||y==0)
    printf("NIE");
    else
    {
        while(y!=2)
        {
            y=y/2;
            if(y%2!=0) break;
        }
        if(y!=2) printf("NIE");
        else printf("TAK");
    }
    return 0;
}

int main()
{
    int a,h,index=31;

    scanf("%d",&a);

    h=a;

    getLog2(a);

    printf("%d \n",licz);

    isPOT(h);

    printf("\n");

    PRINT_DEC_VALUE(index);
    printf("\n");
    PRINT_HEX_VALUE(index);
    printf("\n");
    CODE_STAMP();

    return 0;
}
