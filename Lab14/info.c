#include "info.h"
#include "helper.h"

void readBMPInfo(BMPInfo* info, const unsigned char* buffer, unsigned int* shift) {
    readInt(&(info->size), buffer, shift);
    //printf("Info: size: %d\n", info->size);
    readInt(&(info->pixelsWidth), buffer, shift);
    //printf("Info: pixels width: %d\n", info->pixelsWidth);
    readInt(&(info->pixelsHeight), buffer, shift);
    //printf("Info: pixels height: %d\n", info->pixelsHeight);
    readShort(&(info->planes), buffer, shift);
    //printf("Info: planes: %d\n", info->planes);
    readShort(&(info->bitsPerPixel), buffer, shift);
    //printf("Info: bits per pixel: %d\n", info->bitsPerPixel);
    readInt(&(info->compression), buffer, shift);
    //printf("Info: compression: %d\n", info->compression);
    readInt(&(info->imageSize), buffer, shift);
    //printf("Info: image size: %d\n", info->imageSize);
    readInt(&(info->xPixelsPerMeter), buffer, shift);
    //printf("Info: x pixels per meter: %d\n", info->xPixelsPerMeter);
    readInt(&(info->yPixelsPerMeter), buffer, shift);
    //printf("Info: y pixels per meter: %d\n", info->yPixelsPerMeter);
    readInt(&(info->colorsUsed), buffer, shift);
    //printf("Info: colors used: %d\n", info->colorsUsed);
    readInt(&(info->importantColors), buffer, shift);
    //printf("Info: important colors: %d\n", info->importantColors);

    info->realPixelsWidth = ((info->pixelsWidth + 31) / 32) * 32;
}

void writeBMPInfoToFile(const BMPInfo* info, const unsigned char* filename) {
    writeIntToFile(info->size, filename);
    writeIntToFile(info->pixelsWidth, filename);
    writeIntToFile(info->pixelsHeight, filename);
    writeShortToFile(info->planes, filename);
    writeShortToFile(info->bitsPerPixel, filename);
    writeIntToFile(info->compression, filename);
    writeIntToFile(info->imageSize, filename);
    writeIntToFile(info->xPixelsPerMeter, filename);
    writeIntToFile(info->yPixelsPerMeter, filename);
    writeIntToFile(info->colorsUsed, filename);
    writeIntToFile(info->importantColors, filename);
}

void copyBMPInfo(BMPInfo* copy, const BMPInfo* original) {
    copy->size = original->size;
    copy->pixelsWidth = original->pixelsWidth;
    copy->pixelsHeight = original->pixelsHeight;
    copy->planes = original->planes;
    copy->bitsPerPixel = original->bitsPerPixel;
    copy->compression = original->compression;
    copy->imageSize = original->imageSize;
    copy->xPixelsPerMeter = original->xPixelsPerMeter;
    copy->yPixelsPerMeter = original->yPixelsPerMeter;
    copy->colorsUsed = original->colorsUsed;
    copy->importantColors = original->importantColors;
}
