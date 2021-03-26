#ifndef BMPFIDDLER_H_INCLUDED
#define BMPFIDDLER_H_INCLUDED

typedef unsigned char  byte;
typedef signed char    si1B;
typedef signed short   si2B;
typedef signed int     si4B;

#pragma pack(push, 1)
typedef                 // ## BMPv3 HEADER ###################### //
  struct BmpHeaderTAG   // sizeof(BmpHeader) must be 54 [Byte]    //
{
//// FILE HEADER      //// the very basic (main) file header    ////
  si1B id[2];           /* 0x4D42 must be here, meaning 'B'and'M' */
  si4B fileSize;        /* (xDim * yDim * 3) + 54L + padding      */
  si2B reserved[2];     /* ((ignored))                            */
  si4B dataOffset;      /* 54 [Byte] ((expected))                 */
//// DIB HEADER       //// 'device-independent bitmap' header   ////
  si4B DIBHeaderSize;   /* should be 40 for us *//* 14 + 40 = 54  */
                        /* version-wise values                    */
                        /*   12: (BMPv2) Windows 2.x + OS/2 1.x   */
                        /*   40: (BMPv3) Windows 3.x + Windows NT */
                        /*  108: (BMPv4) Windows 4.x (Windows 95) */
  si4B pixWidth;        /* xDim, horizontal size ((variable))     */
  si4B pixHeight;       /* yDim, vertical ((variable))            */
  si2B biPlanes;        /*  1 assume((fixed)) */
  si2B bitsPerPixel;    /* 24 assume((fixed)) */
  si4B biCompression;   /*  0 assume((fixed)) */
  si4B biImageByteSize; /* ((ignored)) */
  si4B biXPixPerMeter;  /* ((ignored)) */
  si4B biYPixPerMeter;  /* ((ignored)) */
  si4B biClrUsed;       /* ((ignored)) */
  si4B biClrImportant;  /* ((ignored)) */
}
#if defined(__linux__)
  __attribute__((__packed__, aligned(1)))
#endif
  BmpHeader;
#pragma pack(pop)

typedef struct{
    byte* ptr;
    BmpHeader header;
} MemDescriptor;

void printBmpFileHeader(BmpHeader* bmpHdr);
void printBmpDIBHeader(BmpHeader* bmpHdr);
MemDescriptor loadBMP(const char* bmpFileIn);
MemDescriptor saveBMP(const char* bmpFileOut, MemDescriptor m);
MemDescriptor outtakeImg(MemDescriptor img, int xA, int yA, int xB, int yB);

#endif // BMPFIDDLER_H_INCLUDED
