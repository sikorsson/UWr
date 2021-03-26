#include <stdio.h>
#include <limits.h>

int dzielniki(int n)
{
	int i, sum=1;

	for( i=2; i*i<n; i++ ) if( n%i==0 ) sum += i + n/i;

	if( i*i==n ) return sum+i;
	else return sum;
	}

int main()
{
    unsigned int s, znal=0;

    scanf("%u", &s);

    if(s>=INT_MAX)
        {
            printf("BRAK");
        }

    else while(znal==0)
    {
        unsigned int n = dzielniki(s);
        unsigned int m = dzielniki(n);

        if((m == s)&&(s!=n))
            {
                printf("%d %d \n", s, n);
                znal=1;
            }

        s++;

        if(s>=INT_MAX)
        {
            printf("BRAK");
            znal=1;
        }
    }

    return 0;
}
