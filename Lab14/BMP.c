#include <stdio.h>
#include "BMP.h"

Error readBMP(BMP* bmp, const unsigned char* buffer) {
    unsigned int shift = 0;
    readBMPHeader(&(bmp->header), buffer, &shift);
    if (!checkHeader(&(bmp->header))){
        return ERROR_INCORRECT_FORMAT;
    }
    readBMPInfo(&(bmp->info), buffer, &shift);
    if (!checkMonochromatic(&(bmp->info))) {
        return ERROR_ISNT_MONOCHROMATIC;
    }
    bmp->colors = malloc(bmp->info.colorsUsed * sizeof(Color));
    for (int i = 0; i < bmp->info.colorsUsed; i++) {
        readColor(&(bmp->colors[i]), buffer, &shift);
    }
    unsigned int size = bmp->info.realPixelsWidth * bmp->info.pixelsHeight / 32;
    readPixelsArray(&(bmp->pixelsArray), size, (bmp->info.realPixelsWidth), buffer, &shift);
    return SUCCESS;
}

void writeBMPToFile(const BMP* bmp, const unsigned char* filename) {
    FILE* output = fopen(filename, "wb");
    fclose(output);
    writeBMPHeaderToFile(&(bmp->header), filename);
    writeBMPInfoToFile(&(bmp->info), filename);
    for (int i = 0; i < bmp->info.colorsUsed; i++) {
        writeColorToFile(&(bmp->colors[i]), filename);
    }
    writePixelsArrayToFile(&(bmp->pixelsArray), filename);
}

void copyBMP(BMP* copy, const BMP* original) {
    copyBMPHeader(&(copy->header), &(original->header));
    copyBMPInfo(&(copy->info), &(original->info));
    copy->colors = malloc(original->info.colorsUsed * sizeof(Color));
    for (int i = 0; i < original->info.colorsUsed; i++) {
        copy->colors[i] = original->colors[i];
    }
    copyPixelsArray(&(copy->pixelsArray), &(original->pixelsArray));
}
