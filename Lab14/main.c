#include <stdio.h>
#include <string.h>
#include "BMP.h"
#include "errorCatch.h"

int main(int argc, char* argv[])
{
    FILE* input;
    char* inputFileName;
    char* outputDirectory;
    int maxIter = 9999;
    int dumpFreq = 1;
    int wasInputArg = 0;
    int wasOutputArg = 0;
    int wasMaxIterArg = 0;
    int wasDumpFreqArg = 0;
    int wasAnother = 0;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--input")) {
            i++;
            wasInputArg++;
            inputFileName = malloc((strlen(argv[i]) + 1) * sizeof(char));
            for (int j = 0; j < strlen(argv[i]); j++) {
                inputFileName[j] = argv[i][j];
            }
            inputFileName[strlen(argv[i])] = '\0';
        }
        else if (!strcmp(argv[i], "--output")) {
            i++;
            wasOutputArg++;
            outputDirectory = malloc((strlen(argv[i]) + 1) * sizeof(char));
            for (int j = 0; j < strlen(argv[i]); j++) {
                outputDirectory[j] = argv[i][j];
            }
            outputDirectory[strlen(argv[i])] = '\0';
        }
        else if (!strcmp(argv[i], "--max_iter")) {
            i++;
            wasMaxIterArg++;
            maxIter = atoi(argv[i]);
        }
        else if (!strcmp(argv[i], "--dump_freq")) {
            i++;
            wasDumpFreqArg++;
            dumpFreq = atoi(argv[i]);
        }
        else {
            i++;
            wasAnother++;
            if (wasAnother == 1) {
                errorWhat(WARNING_INCORRECT_ARGUMENT);
            }
        }
    }
    if (!wasInputArg || !wasOutputArg) {
        errorWhat(ERROR_NOT_ENOUGH_ARGS);
    }
    if (wasInputArg >= 2 || wasOutputArg >= 2 || wasMaxIterArg >= 2 || wasDumpFreqArg >= 2) {
        errorWhat(WARNING_REDEFINITION_OF_ARGS);
    }
    if (!(input = fopen(inputFileName, "rb"))) {
        errorWhat(ERROR_CANNOT_OPEN_FILE);
    }
    fseek(input, 0, SEEK_END);
    long long sizeOfFile = ftell(input);
    fseek(input, 0, SEEK_SET);
    unsigned char* buffer = malloc(sizeOfFile * sizeof(unsigned char));
    fread(buffer, 1, sizeOfFile, input);
    fclose(input);
    free(inputFileName);

    BMP bmp;
    Error error = readBMP(&bmp, buffer);
    if (error != SUCCESS) {
        free(outputDirectory);
        errorWhat(error);
    }
    free(buffer);
    play(&bmp, outputDirectory, maxIter, dumpFreq);
    free(outputDirectory);



    return 0;
}
