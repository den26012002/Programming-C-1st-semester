#include <stdio.h>
#include "pixelsArray.h"

void readPixelsArray(PixelsArray* pixelsArray, unsigned int size, unsigned int realPixelsWidth, const unsigned char* buffer, unsigned int* shift) {
    pixelsArray->size = size;
    pixelsArray->realPixelsWidth = realPixelsWidth;
    pixelsArray->array = malloc(size * sizeof(unsigned int));
    for (int i = 0; i < size; i++) {
        pixelsArray->array[i] = 0;
        for (int j = 0; j < 4; j++) {
            //printf("%d ", buffer[*shift]);
            pixelsArray->array[i] += (buffer[(*shift)++] << (8 * (3 - j)));
        }
        //printf("%u ", pixelsArray->array[i]);
    }
}

void writePixelsArrayToFile(const PixelsArray* pixelsArray, const unsigned char* filename) {
    FILE* output = fopen(filename, "ab");
    for (int i = 0; i < pixelsArray->size; i++) {
        for (int j = 0; j < 4; j++) {
            fprintf(output, "%c", ((pixelsArray->array[i] >> (8 * (3 - j))) & 255));
        }
    }
    fclose(output);
}

void copyPixelsArray(PixelsArray* copy, const PixelsArray* original) {
    copy->size = original->size;
    copy->realPixelsWidth = original->realPixelsWidth;
    copy->array = malloc(original->size * sizeof(unsigned int));
    for (int i = 0; i < original->size; i++) {
        copy->array[i] = original->array[i];
    }
}

int getPixel(PixelsArray* pixelsArray, int x, int y) {
    int position = y * pixelsArray->realPixelsWidth + x;
    int arrayPosition = position / 32;
    int offset = position % 32;
    return (((pixelsArray->array[arrayPosition]) & (1 << (31 - offset))) >> (31 - offset));
}

void setPixel(PixelsArray* pixelsArray, int x, int y, unsigned int value) {
    if (value > 1) {
        value = 1;
    }
    int position = y * pixelsArray->realPixelsWidth + x;
    int arrayPosition = position / 32;
    int offset = position % 32;
    pixelsArray->array[arrayPosition] &= ~(1 << (31 - offset));
    pixelsArray->array[arrayPosition] |= (value << (31 - offset));
}
