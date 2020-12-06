#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#include "header.h"
#include "info.h"
#include "color.h"
#include "pixelsArray.h"

typedef struct BMP {
    BMPHeader header;
    BMPInfo info;
    Color* colors;
    PixelsArray pixelsArray;
} BMP;

void readBMP(BMP*, const unsigned char*);

void writeBMPToFile(const BMP*, const unsigned char*);

#endif // BMP_H_INCLUDED
