#include <stdio.h>
#include "header.h"
#include "helper.h"

void readBMPHeader(BMPHeader* header, const unsigned char* buffer, unsigned int* shift) {
    for (int i = 0; i < 2; i++) {
        header->identifier[i] = buffer[(*shift)++];
        //printf("Header: identifier: %c\n", header->identifier[i]);
    }
    readInt(&(header->size), buffer, shift);
    //printf("Header: size: %d\n", header->size);
    for (int i = 0; i < 2; i++) {
        readShort(&(header->reserved[i]), buffer, shift);
        //printf("Header: reserved: %d\n", header->reserved[i]);
    }
    readInt(&(header->offset), buffer, shift);
    //printf("Header: offset: %d\n", header->offset);
}

void writeBMPHeaderToFile(const BMPHeader* header, unsigned char* filename) {
    FILE* output = fopen(filename, "ab");
    for (int i = 0; i < 2; i++) {
        fprintf(output, "%c", header->identifier[i]);
    }
    fclose(output);
    writeIntToFile(header->size, filename);
    for (int i = 0; i < 2; i++) {
        writeShortToFile(header->reserved, filename);
    }
    writeIntToFile(header->offset, filename);
}

void copyBMPHeader(BMPHeader* copy, const BMPHeader* original) {
    for (int i = 0; i < 2; i++) {
        copy->identifier[i] = original->identifier[i];
    }
    copy->size = original->size;
    //printf("Header copy: size: %d\n", copy->size);
    for (int i = 0; i < 2; i++) {
        copy->reserved[i] = original->reserved[i];
    }
    copy->offset = original->offset;
}
