#include <stdlib.h>
#include <stdio.h>
#include "info.h"
#include "helper.h"

void createEmptyInfo(ArcInfo* info) {
    info->filesCnt = 0;
    info->framesSize = 0;
    info->frames = malloc(0);
}

void writeInfoToFile(ArcInfo* info, const unsigned char* filename) {
    writeIntToFile(info->framesSize, filename);
    writeIntToFile(info->filesCnt, filename);
    for (int i = 0; i < info->filesCnt; i++) {
        writeFrameToFile(&(info->frames[i]), filename);
    }
}

void readInfo(ArcInfo* info, const unsigned char* buffer, unsigned int* shift) {
    readInt(&(info->framesSize), buffer, shift);
    readInt(&(info->filesCnt), buffer, shift);
    info->frames = malloc(info->filesCnt * sizeof(ArcFrame));
    for (int i = 0; i < info->filesCnt; i++) {
        readFrame(&(info->frames[i]), buffer, shift);
    }
}
