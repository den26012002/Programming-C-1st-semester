#ifndef COMPRESSION_H_INCLUDED
#define COMPRESSION_H_INCLUDED

typedef struct CodeTable {
    unsigned char codeLength[256];
    unsigned long long code[256];
} CodeTable;

typedef struct CompressedHaffmanArchive {
    unsigned char identifier[3];
    int bitsSize;
    CodeTable codeTable;
    unsigned char* buffer;
} CompressedHaffmanArchive;

void findCompressionTable(CompressedHaffmanArchive*, const unsigned char*, const int);

void compressToArchive(CompressedHaffmanArchive*, const unsigned char*, const int);

void writeCompressedHaffmanArchiveToFile(CompressedHaffmanArchive*, const unsigned char*);

void readCompressedHaffmanArchive(CompressedHaffmanArchive*, const unsigned char*);

void decompressArchiveToFile(CompressedHaffmanArchive*, const unsigned char*);

#endif // COMPRESSION_H_INCLUDED
