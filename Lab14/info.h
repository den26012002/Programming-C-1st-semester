#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

typedef struct BMPInfo {
    unsigned int size;
    unsigned int pixelsWidth;
    unsigned int pixelsHeight;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPixelsPerMeter;
    unsigned int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;

    unsigned int realPixelsWidth;
} BMPInfo;

void readBMPInfo(BMPInfo*, const unsigned char*, unsigned int*);

void writeBMPInfoToFile(const BMPInfo*, const unsigned char*);

void copyBMPInfo(BMPInfo*, const BMPInfo*);

#endif // INFO_H_INCLUDED
