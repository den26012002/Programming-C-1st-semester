#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct BMPHeader {
    unsigned char identifier[2];
    unsigned int size;
    unsigned short reserved[2];
    unsigned int offset;
} BMPHeader;

void readBMPHeader(BMPHeader*, const unsigned char*, unsigned int*);

void writeBMPHeaderToFile(const BMPHeader*, unsigned char*);

void copyBMPHeader(BMPHeader*, const BMPHeader*);

#endif // HEADER_H_INCLUDED
