#include "header.h"

void readHeader(Header* header, const unsigned char* buffer, int* shift) {
    for (int i = 0; i < 3; i++) {
        header->identifier[i] = buffer[*shift];
        (*shift)++;
    }
    header->identifier[3] = '\0';
    for (int i = 0; i < 2; i++) {
        header->version[i] = buffer[*shift];
        (*shift)++;
    }
    header->flags.value = buffer[*shift];
    (*shift)++;
    header->size = 0;
    for (int i = 0; i < 4; i++) {
        header->size <<= 7;
        header->size += buffer[*shift];
        (*shift)++;
    }
}
