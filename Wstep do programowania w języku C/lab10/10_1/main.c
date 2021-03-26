#include <stdio.h>
#include <stdlib.h>
#include "bmpFiddler.h"

int main()
{
    MemDescriptor x;
    x = loadBMP("JokerHarley.bmp");
    saveBMP("saveBMP.bmp", x);
    MemDescriptor xOuttake = outtakeImg(x, 500, 500, 500 + 4*100 - 1, 500 + 4*100 - 1);
    saveBMP("saveOuttake.bmp", xOuttake);
    return 0;
}
