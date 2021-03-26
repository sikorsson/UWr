#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

 void colorizeHexBytes(int k)
 {
    printf(0xF << k*4);
 }

void colorizeBinNybbles(int k)
{

}

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0xC);

    int x;
    scanf("%d", &x);
    printf("%x", x);
    //colorizeHexBytes(x);
    return 0;
}
