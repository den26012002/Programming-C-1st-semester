#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "flags.h"
#pragma pack(1)


typedef struct Header {
    char identifier[4];
    char version[2];
    Flags flags;
    int size;
} Header;

void readHeader(Header*, const unsigned char*, int*);

#pragma pack()
#endif // HEADER_H_INCLUDED
