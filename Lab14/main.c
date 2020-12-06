#include <stdio.h>
#include <string.h>
#include "BMP.h"

int main(int argc, char* argv[])
{
    FILE* input;
    char* inputFileName;
    char* outputDirectory;
    int maxIter = 100;
    int dumpFreq = 1;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--input")) {
            i++;
            inputFileName = malloc((strlen(argv[i]) + 1) * sizeof(char));
            for (int j = 0; j < strlen(argv[i]); j++) {
                inputFileName[j] = argv[i][j];
            }
            inputFileName[strlen(argv[i])] = '\0';
        }
        else if (!strcmp(argv[i], "--output")) {
            i++;
            outputDirectory = malloc((strlen(argv[i]) + 1) * sizeof(char));
            for (int j = 0; j < strlen(argv[i]); j++) {
                outputDirectory[j] = argv[i][j];
            }
            outputDirectory[strlen(argv[i])] = '\0';
        }
        else if (!strcmp(argv[i], "--max_iter")) {
            i++;
            maxIter = atoi(argv[i]);
        }
        else if (!strcmp(argv[i], "--dump_freq")) {
            i++;
            dumpFreq = atoi(argv[i]);
        }
    }
    input = fopen(inputFileName, "rb");
    fseek(input, 0, SEEK_END);
    long long sizeOfFile = ftell(input);
    fseek(input, 0, SEEK_SET);
    unsigned char* buffer = malloc(sizeOfFile * sizeof(unsigned char));
    fread(buffer, 1, sizeOfFile, input);
    fclose(input);

    BMP bmp;
    readBMP(&bmp, buffer);
    play(&bmp, outputDirectory, maxIter, dumpFreq);
    free(buffer);
    free(inputFileName);

    return 0;
}
