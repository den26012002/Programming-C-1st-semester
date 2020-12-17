#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct ArcHeader {
    char identifier[3];
    int size;
} ArcHeader;

void createEmptyHeader(ArcHeader*);

void writeHeaderToFile(ArcHeader*, const unsigned char*);

void readHeader(ArcHeader*, const unsigned char*, unsigned int*);

#endif // HEADER_H_INCLUDED
