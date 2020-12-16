#include <stdio.h>
#include "errorCatch.h"

void errorWhat(Error error) {
    switch (error) {
    case ERROR_CANNOT_OPEN_FILE:
        printf("Error: file cannot be opened or doesn't exist\n");
        exit(error);
    case ERROR_INCORRECT_FORMAT:
        printf("Error: entered file format isn't .bmp\n");
        exit(error);
    case ERROR_ISNT_MONOCHROMATIC:
        printf("Error: entered file isn't monochromatic BMP\n");
        exit(error);
    case ERROR_NOT_ENOUGH_ARGS:
        printf("Error: not enough arguments\n");
        exit(error);
    case WARNING_REDEFINITION_OF_ARGS:
        printf("Warning: some argument was defined multiple times (now used the last one)\n");
        break;
    case WARNING_INCORRECT_ARGUMENT:
        printf("Warning: incorrect argument was entered\n");
        break;
    default:
        break;
    }
}

int checkHeader(const BMPHeader* header) {
    if (!(header->identifier[0] == 'B') || !(header->identifier[1] == 'M')) {
        return 0;
    }
    return 1;
}

int checkMonochromatic(const BMPInfo* info) {
    if (!(info->colorsUsed == 2)) {
        return 0;
    }
    return 1;
}
