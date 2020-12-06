#ifndef PIXELSARRAY_H_INCLUDED
#define PIXELSARRAY_H_INCLUDED

typedef struct PixelsArray {
    unsigned int* array;
    unsigned int size;
    unsigned int realPixelsWidth;
} PixelsArray;

void readPixelsArray(PixelsArray*, unsigned int, unsigned int, const unsigned char*, unsigned int*);

void writePixelsArrayToFile(const PixelsArray*, const unsigned char*);

void copyPixelsArray(PixelsArray*, const PixelsArray*);

int getPixel(PixelsArray*, int, int);

void setPixel(PixelsArray*, int, int, unsigned int);

#endif // PIXELSARRAY_H_INCLUDED
