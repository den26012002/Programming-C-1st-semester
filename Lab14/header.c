#include <stdio.h>
#include "header.h"
#include "helper.h"

void readBMPHeader(BMPHeader* header, const unsigned char* buffer, unsigned int* shift) {
    for (int i = 0; i < 2; i++) {
        header->identifier[i] = buffer[(*shift)++];
    }
    readInt(&(header->size), buffer, shift);
    for (int i = 0; i < 2; i++) {
        readShort(&(header->reserved[i]), buffer, shift);
    }
    readInt(&(header->offset), buffer, shift);
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
    for (int i = 0; i < 2; i++) {
        copy->reserved[i] = original->reserved[i];
    }
    copy->offset = original->offset;
}
