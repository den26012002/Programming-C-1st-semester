#include "info.h"
#include "helper.h"

void readBMPInfo(BMPInfo* info, const unsigned char* buffer, unsigned int* shift) {
    readInt(&(info->size), buffer, shift);
    readInt(&(info->pixelsWidth), buffer, shift);
    readInt(&(info->pixelsHeight), buffer, shift);
    readShort(&(info->planes), buffer, shift);
    readShort(&(info->bitsPerPixel), buffer, shift);
    readInt(&(info->compression), buffer, shift);
    readInt(&(info->imageSize), buffer, shift);
    readInt(&(info->xPixelsPerMeter), buffer, shift);
    readInt(&(info->yPixelsPerMeter), buffer, shift);
    readInt(&(info->colorsUsed), buffer, shift);
    readInt(&(info->importantColors), buffer, shift);

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
