#include <stdio.h>
#include "color.h"

void readColor(Color* color, unsigned char* buffer, unsigned int* shift) {
    color->r = buffer[(*shift)++];
    color->g = buffer[(*shift)++];
    color->b = buffer[(*shift)++];
    color->a = buffer[(*shift)++];
}

void writeColorToFile(const Color* color, const unsigned char* filename) {
    FILE* output = fopen(filename, "ab");
    fprintf(output, "%c", color->r);
    fprintf(output, "%c", color->g);
    fprintf(output, "%c", color->b);
    fprintf(output, "%c", color->a);
    fclose(output);
}

void copyColor(Color* copy, const Color* original) {
    copy->r = original->r;
    copy->g = original->g;
    copy->b = original->b;
    copy->a = original->a;
}
