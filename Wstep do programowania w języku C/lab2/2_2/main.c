#include <stdio.h>
#include <stdlib.h>


void rus(char *ros, int len)
{
    char t_rus[len];
    int i=0,j=0;
    while(ros[i]!='\0')
    {
        if((ros[i]=='c'||ros[i]=='C')&&ros[i+1]=='z')
        {
            t_rus[j]='4';
            j++;
            i+=2;
        }
        else if((ros[i]=='s'||ros[i]=='S')&&ros[i+1]=='z')
        {
            t_rus[j]='w';
            j++;
            i+=2;
        }
        else if((ros[i]=='s'||ros[i]=='S')&&ros[i+1]!='z')
        {
            t_rus[j]='C';
            j++;
            i++;
        }
        else if(ros[i]=='i'&&ros[i+1]=='e')
        {
            t_rus[j]='e';
            j++;
            i+=2;
        }
        else if(ros[i]=='b'||ros[i]=='B')
        {
            t_rus[j]='6';
            j++;
            i++;
        }
        else if(ros[i]=='n'||ros[i]=='N')
        {
            t_rus[j]='H';
            j++;
            i++;
        }
        else if(ros[i]=='h'||ros[i]=='H')
        {
            t_rus[j]='X';
            j++;
            i++;
        }
        else if(ros[i]=='ż'||ros[i]=='Ż')
        {
            t_rus[j]='}';
            t_rus[j+1]='|';
            t_rus[j+2]='{';
            j+=3;
            i++;
        }
        else if(ros[i]=='i'&&ros[i]!='e')
        {
            t_rus[j]='N';
            j++;
            i++;
        }
        else if(ros[i]=='w'||ros[i]=='W')
        {
            t_rus[j]='B';
            j++;
            i++;
        }
        else if(ros[i]=='r'||ros[i]=='R')
        {
            t_rus[j]='p';
            j++;
            i++;
        }
        else if(ros[i]=='u'||ros[i]=='U')
        {
            t_rus[j]='y';
            j++;
            i++;
        }
        else if(ros[i]=='k')
        {
            t_rus[j]='K';
            j++;
            i++;
        }
        else if(ros[i]=='l'||ros[i]=='L')
        {
            t_rus[j]='J';
            t_rus[j+1]='T';
            j+=2;
            i++;
        }
        else if(ros[i]=='t')
        {
            t_rus[j]='T';
            j++;
            i++;
        }
        else if(ros[i]=='m')
        {
            t_rus[j]='M';
            j++;
            i++;
        }
        else
        {
            t_rus[j]=ros[i];
            j++;
            i++;
        }
    }
    t_rus[j]='\0';
    int t_rus_len=sizeof(t_rus);sizeof(t_rus[0]);
    printf("%s\n", t_rus);
    eng(t_rus, t_rus_len);
    return;
}

void eng(char *ang, int ang_len)
{
    int i=0;
    while(ang[i]!='\0')
    {
        if(ang[i]=='4')
        {
            printf("ch");
            i++;
        }
        else if(ang[i]=='w')
        {
            printf("sh");
            i++;
        }
        else if(ang[i]=='6')
        {
            printf("b");
            i++;
        }
        else if(ang[i]=='X')
        {
            printf("kh");
            i++;
        }
        else if(ang[i]=='}'&&ang[i+1]=='|'&&ang[i+2]=='{')
        {
            printf("zh");
            i+=3;
        }
        else if(ang[i]=='N')
        {
            printf("ee");
            i++;
        }
        else if(ang[i]=='H')
        {
            printf("n");
            i++;
        }
        else if(ang[i]=='e')
        {
            printf("iye");
            i++;
        }
        else if(ang[i]=='B')
        {
            printf("v");
            i++;
        }
        else if(ang[i]=='p')
        {
            printf("r");
            i++;
        }
        else if(ang[i]=='y')
        {
            printf("u");
            i++;
        }
        else if(ang[i]=='H'&&ang[i+1]!='e')
        {
            printf("n");
            i++;
        }
        else if(ang[i]=='C')
        {
            printf("s");
            i++;
        }
        else if(ang[i]=='K')
        {
            printf("k");
            i++;
        }
        else if(ang[i]=='6'&&ang[i+1]=='e')
        {
            printf("biye");
            i++;
        }
        else if(ang[i]=='J'&&ang[i+1]=='T')
        {
            printf("L");
            i+=2;
        }
        else if(ang[i]=='T')
        {
            printf("t");
            i++;
        }
        else if(ang[i]=='M')
        {
            printf("m");
            i++;
        }
        else
        {
            printf("%c", ang[i]);
            i++;
        }
    }
    return;
}

int main()
{
    char zdanie[] = "Bielka i Strielka";
    int length=sizeof(zdanie)/sizeof(zdanie[0]);
    rus(zdanie, length);
    return 0;
}
