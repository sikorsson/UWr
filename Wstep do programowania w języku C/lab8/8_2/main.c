#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tab[10000] = {};
    int i=0, temp, j=0;
    char c;
    c=getchar();
    while(c!=EOF)
    {
        tab[i]=c;
        i++;
        c=getchar();
    }
    temp=i;
    i=0;
    while(i<temp)
    {
        if(tab[i]=='(')
        {
            j=i+1;
            while(1)
            {
                if(tab[j]==' ') j++;
                else
                {
                    while(tab[j]!=' ')
                    {
                        printf("%c", tab[j]);
                        j++;
                    }
                    i=j+1;
                    break;
                }
            }
            printf("(");
        }
        else if (tab[i]==' ')
        {
            if (tab[i-1]!=' '&&tab[i-1]!='(')
                printf(", ");
            i++;
        }
        else
        {
            printf("%c", tab[i]);
            i++;
        }
    }
    return 0;
}