#include <stdio.h>
#include <stdlib.h>
#include "bmpFiddler.h"

void printBmpFileHeader(BmpHeader* bmpHdr)
{
  printf("BmpFileHeader [fixed size: 14 bytes]\n");
  printf("====================================\n");
  printf("          id: [%c%c]_chr [%X%X]_hex" "\n", bmpHdr->id[0], bmpHdr->id[1], bmpHdr->id[0], bmpHdr->id[1]);
  printf("    fileSize: %d [%X]_hex" "\n", bmpHdr->fileSize, bmpHdr->fileSize);
  printf("  dataOffset: %d [%X]_hex" "\n", bmpHdr->dataOffset, bmpHdr->dataOffset);
  printf("\n");
}


void printBmpDIBHeader(BmpHeader* bmpHdr)
{
  printf("BmpDIBHeader [exp size: %d bytes]\n", bmpHdr->dataOffset - 14);
  printf("=================================\n");
  printf("  headerSize: %d [%X]_hex" "\n", bmpHdr->DIBHeaderSize, bmpHdr->DIBHeaderSize);
  printf("    pixWidth: %d [%X]_hex" "\n", bmpHdr->pixWidth, bmpHdr->pixWidth);
  printf("   pixHeight: %d [%X]_hex" "\n", bmpHdr->pixHeight, bmpHdr->pixHeight);
  printf("bitsPerPixel: %d [%X]_hex" "\n", bmpHdr->bitsPerPixel, bmpHdr->bitsPerPixel);
  printf(" imgByteSize: %d [%X]_hex" "\n", bmpHdr->biImageByteSize, bmpHdr->biImageByteSize);
  printf("-------------\n");
  printf("      pxSize: %d [%X]_hex" "\n", bmpHdr->pixWidth * bmpHdr->pixHeight,
                                           bmpHdr->pixWidth * bmpHdr->pixHeight);
  printf("      bySize: %d [%X]_hex" "\n", bmpHdr->pixWidth * bmpHdr->pixHeight * (bmpHdr->bitsPerPixel / 8),
                                           bmpHdr->pixWidth * bmpHdr->pixHeight * (bmpHdr->bitsPerPixel / 8));
  printf("\n");
}

MemDescriptor loadBMP(const char* bmpFileIn)
{
    FILE *f = fopen(bmpFileIn, "rb");
    MemDescriptor a;
    fread(&a.header, 54, 1, f);
    a.ptr = malloc(a.header.biImageByteSize);
    printBmpFileHeader(&a.header);
    printBmpDIBHeader(&a.header);
    fseek(f, a.header.dataOffset, 0);

    for(int  y=0; y<a.header.pixHeight; y++)
    {
        for(int x=0; x<a.header.pixWidth; x++)
        {
            fread(&a.ptr[(y*a.header.pixWidth+x)*3], 3, 1, f);
        }
    }
    fclose(f);
    return a;
}

MemDescriptor saveBMP(const char* bmpFileOut, MemDescriptor m)
{
    FILE *f = fopen(bmpFileOut, "wb+");
    fwrite(&m.header, 54, 1, f);
    for(int  y=0; y<m.header.pixHeight; y++)
    {
        for(int x=0; x<m.header.pixWidth; x++)
        {
            fwrite(&m.ptr[(y*m.header.pixWidth+x)*3], 3, 1, f);
        }
    }
    fclose(f);
    return;
}

MemDescriptor outtakeImg(MemDescriptor img, int xA, int yA, int xB, int yB)
{
    MemDescriptor a = {0};

    a.header = img.header;
    a.header.pixHeight = yB-yA+1;
    a.header.pixWidth = xB-xA+1;
    a.header.biImageByteSize = a.header.pixHeight * a.header.pixWidth * (a.header.bitsPerPixel / 8);
    a.header.fileSize = a.header.biImageByteSize + a.header.dataOffset;

    a.ptr = malloc(a.header.biImageByteSize);

    for(int  y=yA; y<=yB; y++)
    {
        for(int x=xA; x<=xB; x++)
        {
            a.ptr[((y-yA) * a.header.pixWidth + (x-xA))*3 +0] = img.ptr[(y*img.header.pixWidth+x)*3 +0];
            a.ptr[((y-yA) * a.header.pixWidth + (x-xA))*3 +1] = img.ptr[(y*img.header.pixWidth+x)*3 +1];
            a.ptr[((y-yA) * a.header.pixWidth + (x-xA))*3 +2] = img.ptr[(y*img.header.pixWidth+x)*3 +2];
        }
    }
    return a;
}
