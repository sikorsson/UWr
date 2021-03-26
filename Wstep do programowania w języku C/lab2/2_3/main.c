#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char znaki[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','w','x','y','z',' ',','};
    char typ[7], permutacja[64], klucz[256], tekst[256], x='0';
    int i=0;
    scanf("%s", typ);
    while(i<64)
    {
        int perm;
        scanf("%d", &perm);
        permutacja[i]=perm;
        i++;
    }
    x='0';
    i=0;
    while(x!='\n')
    {
        scanf("%c", x);
        klucz[i]=x;
        i++;
    }
    x='0';
    i=0;
    while(x!='\n')
    {
        scanf("%c", x);
        tekst[i]=x;
        i++;
    }

    int temp;
    //while()
    //{
        if(x>='0'&&x<='9') temp=(int)x-48;
        else if(x>='A'&&x<='Z') temp=(int)x-55;
        else if(x>='a'&&x<='z') temp=(int)x-61;
        else if(x==' ') temp=62;
        else if(x==',') temp=63;
        printf("%d", temp);

    //}
    return 0;
}
