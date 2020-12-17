#include "archive.h"
#include <string.h>
#include <stdio.h>

void createEmptyArchive(Archive* archive) {
    archive->files = malloc(0);
    createEmptyHeader(&(archive->header));
    createEmptyInfo(&(archive->info));
}

void addFileToArchive(Archive* archive, const unsigned char* fileName, const int fileSize, const unsigned char* fileBuffer) {
    int filesCnt = ++(archive->info.filesCnt);
    archive->info.framesSize += strlen(fileName) + 1 + 3 * sizeof(int);
    archive->info.frames = realloc(archive->info.frames, filesCnt * sizeof(ArcFrame));
    archive->info.frames[filesCnt - 1].fileNameSize = strlen(fileName) + 1;
    archive->info.frames[filesCnt - 1].fileSize = fileSize + 1;
    archive->info.frames[filesCnt - 1].fileName = malloc((strlen(fileName) + 1) * sizeof(unsigned char));
    for (int i = 0; i < strlen(fileName); i++) {
        archive->info.frames[filesCnt - 1].fileName[i] = fileName[i];
    }
    archive->info.frames[filesCnt - 1].fileName[strlen(fileName)] = '\0';
    archive->header.size += 3 * sizeof(int) + strlen(fileName) + 1;
    archive->info.frames[filesCnt - 1].offset = archive->header.size + 3 + sizeof(int);
    for (int i = 0; i < filesCnt - 1; i++) {
        archive->info.frames[i].offset += strlen(fileName) + 1 + 3 * sizeof(int);
    }
    archive->files = realloc(archive->files, filesCnt * sizeof(unsigned char*));
    archive->files[filesCnt - 1] = malloc((fileSize + 1) * sizeof(unsigned char));
    for (int i = 0; i < fileSize; i++) {
        archive->files[filesCnt - 1][i] = fileBuffer[i];
    }
    archive->files[filesCnt - 1][fileSize] = '\0';
    archive->header.size += fileSize + 1;
}

void writeArchiveToFile(const Archive* archive, const unsigned char* filename) {
    FILE* output = fopen(filename, "wb");
    fclose(output);
    writeHeaderToFile(&(archive->header), filename);
    writeInfoToFile(&(archive->info), filename);
    output = fopen(filename, "ab");
    for (int i = 0; i < archive->info.filesCnt; i++) {
        for (int j = 0; j < archive->info.frames[i].fileSize; j++) {
            fprintf(output, "%c", archive->files[i][j]);
            //printf("%c", archive->files[i][j]);
              //printf("I'm here!\n");
        }
    }
    fclose(output);
}

void readArchive(Archive* archive, const unsigned char* buffer) {
    unsigned int shift = 0;
    readHeader(&(archive->header), buffer, &shift);
    readInfo(&(archive->info), buffer, &shift);
    archive->files = malloc(archive->info.filesCnt * sizeof(unsigned char*));
    for (int i = 0; i < archive->info.filesCnt; i++) {
        archive->files[i] = malloc(archive->info.frames[i].fileSize * sizeof(unsigned char));
        for (int j = 0; j < archive->info.frames[i].fileSize; j++) {
            archive->files[i][j] = buffer[shift++];
        }
    }
}

void unpackArchive(Archive* archive) {
    for (int i = 0; i < archive->info.filesCnt; i++) {
        FILE* output = fopen(archive->info.frames[i].fileName, "wb");
        for (int j = 0; j < archive->info.frames[i].fileSize - 1; j++) {
            fprintf(output, "%c", archive->files[i][j]);
        }
        fclose(output);
    }
}

void showArchiveList(Archive* archive) {
    for (int i = 0; i < archive->info.filesCnt; i++) {
        printf("-%s\n", archive->info.frames[i].fileName);
    }
}
