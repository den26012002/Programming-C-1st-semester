#include <stdio.h>
#include <string.h>
#include "header.h"
#include "frameV2.h"
#include "metadataV2.h"
#include "mp3V2.h"
#include "errorCatch.h"
#pragma pack(1)

int main(int argc, char* argv[])
{
    FILE *input;
    FILE *output;
    char* filename = malloc(strlen(argv[1] + 1) * sizeof(char));
    for (int i = 0; i < strlen(argv[1]); i++) {
           filename[i] = argv[1][i];
    }
    filename[strlen(argv[1])] = '\0';
    char* outputFileName = malloc(strlen(argv[1] + 1) * sizeof(char));
    for (int i = 0; i < strlen(argv[1]); i++) {
           outputFileName[i] = argv[1][i];
    }
    outputFileName[strlen(argv[1])] = '\0';
    input = fopen(filename, "rb");
    fseek(input, 0, SEEK_END);
    long long sizeOfFile = ftell(input);
    fseek(input, 0, SEEK_SET);
    unsigned char *buffer = malloc(sizeOfFile * sizeof(unsigned char));
    fread(buffer, 1, sizeOfFile, input);
    fclose(input);
    MP3V2 mp3;
    readMP3V2(&mp3, buffer, sizeOfFile);
    if (!strcmp(argv[2], "--show")) {
        showAllFramesV2(&(mp3.metadata));
    }
    else if (!strncmp(argv[2], "--get=", 6)) {
        char* name = malloc((strlen(argv[2]) - 6 + 1) * sizeof(char));
        for (int i = 6; i < strlen(argv[2]); i++) {
            name[i - 6] = argv[2][i];
        }
        name[strlen(argv[2]) - 6] = '\0';
        showFrameWithNameV2(&(mp3.metadata), name);
    }
    else if (!strncmp(argv[2], "--set=", 6)) {
        char* name = malloc((strlen(argv[2]) - 6 + 1) * sizeof(char));
        for (int i = 6; i < strlen(argv[2]); i++) {
            name[i - 6] = argv[2][i];
        }
        name[strlen(argv[2]) - 6] = '\0';
        char* value = malloc((strlen(argv[3]) - 8 + 1) * sizeof(char));
        for (int i = 8; i < strlen(argv[3]); i++) {
            value[i - 8] = argv[3][i];
        }
        value[strlen(argv[3]) - 8] = '\0';
        editFrameWithNameV2(&(mp3.metadata), name, value);
        SaveChangesToFileV2(outputFileName, &mp3);
    }
    free(filename);
    free(outputFileName);

#pragma pack()
    return 0;
}
