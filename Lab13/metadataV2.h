#ifndef METADATAV2_H_INCLUDED
#define METADATAV2_H_INCLUDED
#include "header.h"
#include "frameV2.h"

typedef struct MetadataV2 {
    Header header;
    FrameV2* frames;
    int cntFrames;
} MetadataV2;

void readMetadataV2(MetadataV2*, const unsigned char*);

void showAllFramesV2(MetadataV2*);

void showFrameWithNameV2(MetadataV2*, const char*);

void editFrameWithNameV2(MetadataV2*, const char*, const char*);

#endif // METADATAV2_H_INCLUDED
