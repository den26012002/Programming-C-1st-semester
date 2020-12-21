#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archive.h"
#include "compression.h"

int main(int argc, char* argv[])
{
    Archive archive;
    unsigned char* archiveName;
    if (!strcmp(argv[1], "--file")) {
        archiveName = argv[2];
    }
    if (!strcmp(argv[3], "--create")) {
        printf("Creating started...\n");
        createEmptyArchive(&archive);
        for (int i = 4; i < argc; i++) {
            printf("%s added...\n", argv[i]);
            unsigned char* buffer;
            int fileSize = readFileToBuffer(&buffer, argv[i]);
            addFileToArchive(&archive, argv[i], fileSize, buffer);
        }
        writeArchiveToFile(&archive, archiveName);
        printf("Creating finished!\n");

    }
    else {
        unsigned char* buffer;
        readFileToBuffer(&buffer, archiveName);
        readArchive(&archive, buffer);
        if (!strcmp(argv[3], "--extract")) {
            unpackArchive(&archive);
        }
        else if (!strcmp(argv[3], "--list")) {
            showArchiveList(&archive);
        }
    }

    //unsigned char* buffer1;
    //int fileSize1 = readFileToBuffer(&buffer1, archiveName);


    //CompressedHaffmanArchive arc;

    //расжатие
    //readCompressedHaffmanArchive(&arc, buffer1);
    //decompressArchiveToFile(&arc, archiveName);

    //сжатие
    //findCompressionTable(&arc, buffer1, fileSize1);
    //compressToArchive(&arc, buffer1, fileSize1);
    //writeCompressedHaffmanArchiveToFile(&arc, archiveName);




    return 0;
}
