#ifndef ARCHIVE_H_INCLUDED
#define ARCHIVE_H_INCLUDED
#include "header.h"
#include "info.h"

typedef struct Archive {
    ArcHeader header;
    ArcInfo info;
    unsigned char** files;
} Archive;

void createEmptyArchive(Archive*);

void addFileToArchive(Archive*, const unsigned char*, const int, const unsigned char*);

void writeArchiveToFile(const Archive*, const unsigned char*);

void readArchive(Archive*, const unsigned char*);

void unpackArchive(Archive*);

void showArchiveList(Archive*);

#endif // ARCHIVE_H_INCLUDED
