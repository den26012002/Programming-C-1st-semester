#include <stdio.h>
#include "header.h"

void createEmptyHeader(ArcHeader* header) {
    header->identifier[0] = 'A';
    header->identifier[1] = 'R';
    header->identifier[2] = 'C';
    header->size = 2 * sizeof(int);
}

void writeHeaderToFile(ArcHeader* header, const unsigned char* filename) {
    FILE* output = fopen(filename, "ab");
    for (int i = 0; i < 3; i++) {
        fprintf(output, "%c", header->identifier[i]);
    }
    fclose(output);
    writeIntToFile(header->size, filename);
}

void readHeader(ArcHeader* header, const unsigned char* buffer, unsigned int* shift) {
    for (int i = 0; i < 3; i++) {
        header->identifier[i] = buffer[(*shift)++];

    }
    readInt(&(header->size), buffer, shift);
}
