#include <stdio.h>
#include <string.h>
#include "mp3V2.h"

void readMP3V2(MP3V2* mp3, const char* buffer, int sizeOfFile) {
    readMetadataV2(&(mp3->metadata), buffer);
    mp3->musicInfo = malloc((sizeOfFile - mp3->metadata.header.size) * sizeof(unsigned char));
    for (int i = mp3->metadata.header.size; i < sizeOfFile; i++) {
        mp3->musicInfo[i - mp3->metadata.header.size] = buffer[i];
    }
    mp3->musicInfoSize = sizeOfFile - mp3->metadata.header.size;
}

void writeHeaderToFileV2(const char* fileName, MP3V2* mp3) {
    FILE* output = fopen(fileName, "w+b");
    for (int i = 0; i < 3; i++) {
        fprintf(output, "%c", mp3->metadata.header.identifier[i]);
    }
    for (int i = 0; i < 2; i++) {
        fprintf(output, "%c", mp3->metadata.header.version[i]);
    }
    fprintf(output, "%c", mp3->metadata.header.flags.value);
    char size[4];
    int headerSize = mp3->metadata.header.size;
    for (int i = 3; i >= 0; i--) {
        size[i] = headerSize & 127;
        headerSize >>= 7;
    }
    for (int i = 0; i < 4; i++) {
        fprintf(output, "%c", size[i]);
    }
    fclose(output);
}

void writeFramesToFileV2(const char* fileName, MP3V2* mp3) {
    FILE* output = fopen(fileName, "a+b");
    int cntsymbs = 0;
    for (int k = 0; k < mp3->metadata.cntFrames; k++) {
        if (mp3->metadata.frames[k].size == 0 || (mp3->metadata.frames[k].identifier[0] != 'T' && mp3->metadata.frames[k].identifier[0] != 'C')) {
            continue;
        }
        for (int i = 0; i < 3; i++) {
            fprintf(output, "%c", mp3->metadata.frames[k].identifier[i]);
            cntsymbs++;
        }
        char size[3];
        int frameSize = mp3->metadata.frames[k].size;
        for (int i = 2; i >= 0; i--) {
            size[i] = frameSize & 255;
            frameSize >>= 8;
        }
        for (int i = 0; i < 3; i++) {
            fprintf(output, "%c", size[i]);
            cntsymbs++;
        }
        if (mp3->metadata.frames[k].identifier[0] == 'T' || mp3->metadata.frames[k].identifier[0] == 'C') {
            fprintf(output, "%c", mp3->metadata.frames[k].textEncoding);
            cntsymbs++;
        }
        for (int i = 0; i < mp3->metadata.frames[k].size - 1; i++) {
            fprintf(output, "%c", mp3->metadata.frames[k].value[i]);
            cntsymbs++;
        }
    }
    for (int k = 0; k < mp3->metadata.cntFrames; k++) {
        if (mp3->metadata.frames[k].size == 0 || mp3->metadata.frames[k].identifier[0] == 'T' || mp3->metadata.frames[k].identifier[0] == 'C') {
            continue;
        }
        for (int i = 0; i < 3; i++) {
            fprintf(output, "%c", mp3->metadata.frames[k].identifier[i]);
            cntsymbs++;
        }
        char size[3];
        int frameSize = mp3->metadata.frames[k].size;
        for (int i = 2; i >= 0; i--) {
            size[i] = frameSize & 255;
            frameSize >>= 8;
        }
        for (int i = 0; i < 3; i++) {
            fprintf(output, "%c", size[i]);
            cntsymbs++;
        }
        if (mp3->metadata.frames[k].identifier[0] == 'T' || mp3->metadata.frames[k].identifier[0] == 'C') {
            fprintf(output, "%c", mp3->metadata.frames[k].textEncoding);
            cntsymbs++;
        }
        for (int i = 0; i < mp3->metadata.frames[k].size - 1; i++) {
            fprintf(output, "%c", mp3->metadata.frames[k].value[i]);
            cntsymbs++;
        }
    }
    for (int i = cntsymbs; i < mp3->metadata.header.size; i++) {
        fprintf(output, "%c", 0);
    }
    fclose(output);
}

void writeMusicInfoToFileV2(const char* fileName, MP3V2* mp3) {
    FILE* output = fopen(fileName, "a+b");
    for (int i = 0; i < mp3->musicInfoSize; i++) {
        fprintf(output, "%c", mp3->musicInfo[i]);
    }
    fclose(output);
}

void SaveChangesToFileV2(const char* fileName, MP3V2* mp3) {
    writeHeaderToFileV2(fileName, mp3);
    writeFramesToFileV2(fileName, mp3);
    writeMusicInfoToFileV2(fileName, mp3);
}
