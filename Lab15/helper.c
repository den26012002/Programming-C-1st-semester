#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void readInt(unsigned int* value, const unsigned char* buffer, unsigned int* shift) {
    *value = 0;
    for (int i = 0; i < 4; i++) {
        *value += (buffer[(*shift)++] << (8 * i));
    }
}

void readShort(unsigned short* value, const unsigned char* buffer, unsigned int* shift) {
    *value = 0;
    for (int i = 0; i < 2; i++) {
        *value += (buffer[(*shift)++] << (8 * i));
    }
}

void writeIntToFile(unsigned int value, const unsigned char* filename) {
    FILE* output = fopen(filename, "ab");
    for (int i = 0; i < 4; i++) {
        fprintf(output, "%c", ((value >> (8 * i)) & 255));
    }
    fclose(output);
}

void writeShortToFile(unsigned short value, const unsigned char* filename) {
    FILE* output = fopen(filename, "ab");
    for (int i = 0; i < 2; i++) {
        fprintf(output, "%c", ((value >> (8 * i)) & 255));
    }
    fclose(output);
}

int readFileToBuffer(unsigned char** buffer, const unsigned char* filename) {
    FILE* input = fopen(filename, "rb");
    fseek(input, 0, SEEK_END);
    long long sizeOfFile = ftell(input);
    fseek(input, 0, SEEK_SET);
    *buffer = malloc(sizeOfFile * sizeof(unsigned char));
    fread(*buffer, 1, sizeOfFile, input);
    fclose(input);
    return sizeOfFile;
}
