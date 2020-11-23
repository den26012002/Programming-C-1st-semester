#ifndef FRAMEV2_H_INCLUDED
#define FRAMEV2_H_INCLUDED
typedef struct FrameV2 {
    unsigned char identifier[4];
    int size;
    char textEncoding;
    char* value;
} FrameV2;

void readFrameV2(FrameV2*, const unsigned char*, int*);

#endif // FRAMEV2_H_INCLUDED
