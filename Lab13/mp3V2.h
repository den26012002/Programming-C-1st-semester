#ifndef MP3V2_H_INCLUDED
#define MP3V2_H_INCLUDED
#include "metadataV2.h"

typedef struct MP3V2 {
    MetadataV2 metadata;
    unsigned char* musicInfo;
    int musicInfoSize;
} MP3V2;

void readMP3V2(MP3V2*, const char*, int);

void writeHeaderToFileV2(const char*, MP3V2*);

void writeFramesToFileV2(const char*, MP3V2*);

void writeMusicInfoToFileV2(const char*, MP3V2*);

void SaveChangesToFileV2(const char*, MP3V2*);

#endif // MP3V2_H_INCLUDED
