#include <stdio.h>
#include <stdlib.h>

void p1(int **tab, int x)
{
    int temp;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            scanf("%d", &temp);
            tab[i][j]=temp;
        }
    }
    return;
}

int row()
{

}

int snake()
{

}

int diagonal()
{

}




int main()
{
    char typ[2];
    scanf("%s", &typ);
    int n;
    scanf("%d", &n);
    int tablica[n][n];
    if(typ[0]=='P') scanf("%d", &n);

    if(typ[0]=='P') p1(tablica, n);
    //else if(typ=="RR") row(tablica,n);

    return 0;
}
