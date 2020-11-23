#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "metadataV2.h"
#include "errorCatch.h"

void readMetadataV2(MetadataV2* metadata, const unsigned char* buffer) {
    int shift = 0;
    readHeader(&(metadata->header), buffer, &shift);
    metadata->cntFrames = 0;
    metadata->frames = malloc(sizeof(FrameV2));
    while (shift < metadata->header.size + 10) {
        if (buffer[shift] == 0) {
            break;
        }
        metadata->cntFrames++;
        metadata->frames = realloc(metadata->frames, (metadata->cntFrames) * sizeof(FrameV2));
        readFrameV2(&(metadata->frames[metadata->cntFrames - 1]), buffer, &shift);
    }
}

void showAllFramesV2(MetadataV2* metadata) {
    printf("Name | Value\n");
    printf("\n");
    for (int i = 0; i < metadata->cntFrames; i++) {
        if (metadata->frames[i].identifier[0] == 'T') {
            printf("%s  | %s\n", metadata->frames[i].identifier, metadata->frames[i].value);
        }
    }
}

void showFrameWithNameV2(MetadataV2* metadata, const char* name) {
    for (int i = 0; i < metadata->cntFrames; i++) {
        if (!strcmp(metadata->frames[i].identifier, name)) {
            printf("Name | Value\n");
            printf("\n");
            printf("%s   | %s\n", metadata->frames[i].identifier, metadata->frames[i].value);
            return;
        }
    }
    printf("Error: there is no frame with such name");
}

void editFrameWithNameV2(MetadataV2* metadata, const char* name, const char* newvalue) {
    int newsize = strlen(newvalue) + 2;
    for (int i = 0; i < metadata->cntFrames; i++) {
        if (!strcmp(metadata->frames[i].identifier, name)) {
            metadata->header.size -= metadata->frames[i].size;
            metadata->header.size += newsize;
            metadata->frames[i].size = newsize;
            metadata->frames[i].value = newvalue;
            return;
        }
    }
    if (!checkIdentifier(name)) {
        printf("Error: incorrect identifier of frame!");
        return;
    }
    metadata->header.size += newsize + 10;
    metadata->cntFrames++;
    metadata->frames = realloc(metadata->frames, (metadata->cntFrames) * sizeof(FrameV2));
    for (int i = 0; i < 3; i++) {
        metadata->frames[metadata->cntFrames - 1].identifier[i] = name[i];
    }
    metadata->frames[metadata->cntFrames - 1].identifier[3] = '\0';
    metadata->frames[metadata->cntFrames - 1].size = newsize;
    metadata->frames[metadata->cntFrames - 1].textEncoding = 0;
    metadata->frames[metadata->cntFrames - 1].value = newvalue;
}
