#include <stdio.h>
#include <stdlib.h>

int beautifyString(char *txt, int len)
{
    char ready[len];
    int i=0,j=0;
    while(txt[i]!='\0')
    {
        if(txt[i]!=' '||txt[i+1]!=' ')
        {
            ready[j]=txt[i];
            j++;
        }
        i++;
    }
    ready[j-1]='\0';

    if(ready[0]>='a'&&ready[0]<='z') ready[0]=ready[0]-32;
    if(ready[1]>='A'&&ready[1]<='Z') ready[1]=ready[1]+32;

    i=2;

    while(ready[i]!='\0')
    {
        if(ready[i-2]=='.'||ready[i-2]=='!'||ready[i-1]=='.'||ready[i-1]=='!')
        {
            if(ready[i]>='a'&&ready[i]<='z') ready[i]=ready[i]-32;
        }
        else if(ready[i]>='A'&&ready[i]<='Z') ready[i]=ready[i]+32;
        i++;
    }
    printf("%s\n", ready);
    return j-1;
}


int main()
{
    char txt[20]="Al.a!     ma   KOTA!";
    int len=20,nowa;
    nowa=beautifyString(txt,len);
    printf("Nowa dlugosc = %d", nowa);
    return 0;
}
