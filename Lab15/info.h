#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED
#include "frame.h"

typedef struct ArcInfo {
    int framesSize;
    int filesCnt;
    ArcFrame* frames;
} ArcInfo;

void createEmptyInfo(ArcInfo*);

void readInfo(ArcInfo*, const unsigned char*, unsigned int*);

#endif // INFO_H_INCLUDED
