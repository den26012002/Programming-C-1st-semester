#include <stdio.h>
#include "frame.h"
#include "helper.h"

void writeFrameToFile(ArcFrame* frame, const unsigned char* filename) {
    writeIntToFile(frame->fileNameSize, filename);
    writeIntToFile(frame->fileSize, filename);
    writeIntToFile(frame->offset, filename);
    FILE* output = fopen(filename, "ab");
    for (int i = 0; i < frame->fileNameSize; i++) {
        fprintf(output, "%c", frame->fileName[i]);
    }
    fclose(output);
}

void readFrame(ArcFrame* frame, const unsigned char* buffer, unsigned int* shift) {
    readInt(&(frame->fileNameSize), buffer, shift);
    readInt(&(frame->fileSize), buffer, shift);
    readInt(&(frame->offset), buffer, shift);
    frame->fileName = malloc(frame->fileSize * sizeof(unsigned char));
    for (int i = 0; i < frame->fileNameSize; i++) {
        frame->fileName[i] = buffer[(*shift)++];
    }
}
