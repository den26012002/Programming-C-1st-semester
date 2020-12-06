#include <stdio.h>
#include "BMP.h"

void readBMP(BMP* bmp, const unsigned char* buffer) {
    //printf("Read bmp started\n");
    unsigned int shift = 0;
    readBMPHeader(&(bmp->header), buffer, &shift);
    //printf("Shift: %d\n", shift);
    readBMPInfo(&(bmp->info), buffer, &shift);
    //printf("Shift: %d\n", shift);
    //printf("Read BMP: info: colors used: %d\n", bmp->info.colorsUsed);
    bmp->colors = malloc(bmp->info.colorsUsed * sizeof(Color));
    for (int i = 0; i < bmp->info.colorsUsed; i++) {
        readColor(&(bmp->colors[i]), buffer, &shift);
        //printf("Shift: %d\n", shift);
    }
    unsigned int size = bmp->info.realPixelsWidth * bmp->info.pixelsHeight / 32;
    readPixelsArray(&(bmp->pixelsArray), size, (bmp->info.realPixelsWidth), buffer, &shift);
    //printf("Shift: %d\n", shift);
    //printf("Read bmp finished\n");
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
