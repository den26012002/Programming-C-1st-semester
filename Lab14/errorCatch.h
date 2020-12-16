#ifndef ERRORCATCH_H_INCLUDED
#define ERRORCATCH_H_INCLUDED

#include "BMP.h"

typedef enum Error {
    SUCCESS,
    ERROR_CANNOT_OPEN_FILE,
    ERROR_INCORRECT_FORMAT,
    ERROR_ISNT_MONOCHROMATIC,
    ERROR_NOT_ENOUGH_ARGS,
    WARNING_REDEFINITION_OF_ARGS,
    WARNING_INCORRECT_ARGUMENT
} Error;

void errorWhat(Error);

int checkHeader(const BMPHeader*);

int checkMonochromatic(const BMPInfo* info);

#endif // ERRORCATCH_H_INCLUDED
