#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

typedef struct ArcFrame {
    int fileNameSize;
    int fileSize;
    int offset;
    unsigned char* fileName;
} ArcFrame;

void writeFrameToFile(ArcFrame*, const unsigned char*);

void readFrame(ArcFrame*, const unsigned char*, unsigned int*);

#endif // FRAME_H_INCLUDED
