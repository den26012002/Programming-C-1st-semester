#include <stdio.h>
#include <stdlib.h>
#include "compression.h"
#include "helper.h"

void findCompressionTable(CompressedHaffmanArchive* archive, const unsigned char* buffer, const int bufferSize) {
    unsigned char freq[256];
    unsigned char value[256];
    unsigned char similar[256];
    for (int i = 0; i < 256; i++) {
        freq[i] = 0;
        value[i] = i;
        similar[i] = 1;
    }
    for (int i = 0; i < bufferSize; i++) {
        freq[buffer[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (!freq[i]) {
            similar[i] = 0;
        }
    }
    for (int i = 0; i < 256; i++) {
        archive->codeTable.code[i] = 0;
        archive->codeTable.codeLength[i] = 0;
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 255; j++) {
            if (freq[j] == 0 || (freq[j] > freq[j + 1] && freq[j + 1] != 0)) {
                swapC(&freq[j], &freq[j + 1]);
                swapC(&similar[j], &similar[j + 1]);
                swapC(&value[j], &value[j + 1]);
            }
        }
    }
    int b = 1;
    while (b) {
        int it1 = 0;
        int it2 = similar[it1];
        if (it2 >= 256 || freq[it2] == 0) {
            b = 0;
            for (int i = it1; i < it2; i++) {
                //archive->codeTable.codeLength[value[i]]++;
                //archive->codeTable.code[value[i]] |= (0 << archive->codeTable.codeLength[value[i]]);
            }
        }
        else {
            for (int i = it1; i < it1 + similar[it1]; i++) {
                //printf("0 added to %c\n", value[i]);
                archive->codeTable.code[value[i]] |= (0 << archive->codeTable.codeLength[value[i]]);
                archive->codeTable.codeLength[value[i]]++;
            }
            for (int i = it2; i < it2 + similar[it2]; i++) {
                //printf("1 added to %c\n", value[i]);
                archive->codeTable.code[value[i]] |= (1 << archive->codeTable.codeLength[value[i]]);
                archive->codeTable.codeLength[value[i]]++;
            }
            int newFreq = freq[it1] + freq[it2];
            int newSimilar = similar[it1] + similar[it2];
            int it3 = it2 + similar[it2];
            for (int i = it1; i < it3; i++) {
                freq[i] = newFreq;
                similar[i] = newSimilar;
            }
            for (int i = 0; i < 256; i++) {
                for (int j = 0; j < 255; j++) {
                    if (freq[j] == 0 || (freq[j] > freq[j + 1] && freq[j + 1] != 0)) {
                        swapC(&freq[j], &freq[j + 1]);
                        swapC(&similar[j], &similar[j + 1]);
                        swapC(&value[j], &value[j + 1]);
                    }
                }
            }
        }
        for (int i = 0; i < 256; ++i) {
            if (freq[i] != 0) {
                //printf("%c: %d   %d\n", value[i], freq[i], similar[i]);
            }
        }
        //printf("\n\n");
    }

}

void setBit(CompressedHaffmanArchive* archive, int bitPos, int bitValue) {
    int pos = bitPos / 8;
    int shift = bitPos % 8;
    archive->buffer[pos] |= (bitValue << (7 - shift));
}

int getBit (CompressedHaffmanArchive* archive, int bitPos) {
    int pos = bitPos / 8;
    int shift = bitPos % 8;
    return ((archive->buffer[pos] & (1 << (7 - shift))) >> (7 - shift));
}

void writeCompressedSymbolToArchive(CompressedHaffmanArchive* archive, const unsigned char symb) {
    for (int i = 0; i < archive->codeTable.codeLength[symb]; i++) {
        if (archive->bitsSize % 8 == 0) {
            //archive->buffer = realloc(archive->buffer, (archive->bitsSize + 1) * sizeof(unsigned char));
        }
        int bitValue = (archive->codeTable.code[symb] & (1 << (archive->codeTable.codeLength[symb] - i - 1))) >> (archive->codeTable.codeLength[symb] - i - 1);
        //int bitValue = (archive->codeTable.code[symb] & (1 << (i))) >> (i);
        //printf("%d", bitValue);
        setBit(archive, archive->bitsSize, bitValue);
        archive->bitsSize++;
    }
}

void compressToArchive(CompressedHaffmanArchive* archive, const unsigned char* buffer, const int bufferSize) {
    archive->identifier[0] = 'C';
    archive->identifier[1] = 'H';
    archive->identifier[2] = 'A';
    archive->buffer = (unsigned char*)calloc(archive->buffer, bufferSize);
    printf("%p\n", archive->buffer);
    archive->bitsSize = 0;
    for (int i = 0; i < bufferSize; i++) {
        //printf("I'm writing now... %d of %d has done\n", i + 1, bufferSize);
        writeCompressedSymbolToArchive(archive, buffer[i]);
        //printf("Bits size: %d\n", archive->bitsSize);
        //printf("Value: %d\n\n", archive->buffer[0]);
    }
}

void writeCompressedHaffmanArchiveToFile(CompressedHaffmanArchive* archive, const unsigned char* filename) {
    FILE* output = fopen(filename, "wb");
    for (int i = 0; i < 3; i++) {
        fprintf(output, "%c", archive->identifier[i]);
    }
    fclose(output);
    writeIntToFile(archive->bitsSize, filename);
    for (int i = 0; i < 256; i++) {
        writeCharToFile(archive->codeTable.codeLength[i], filename);
        writeLongLongToFile(archive->codeTable.code[i], filename);
    }
    for (int i = 0; i < (archive->bitsSize + 7) / 8; i++) {
        writeCharToFile(archive->buffer[i], filename);
    }
    //printf("I'm here!\n");
}

void readCompressedHaffmanArchive(CompressedHaffmanArchive* archive, const unsigned char* buffer) {
    int shift = 0;
    for (int i = 0; i < 3; i++) {
        archive->identifier[i] = buffer[shift++];
    }
    readInt(&(archive->bitsSize), buffer, &shift);
    for (int i = 0; i < 256; i++) {
        readChar(&(archive->codeTable.codeLength[i]), buffer, &shift);
        readLongLong(&(archive->codeTable.code[i]), buffer, &shift);
    }
    archive->buffer = calloc(archive->buffer, ((archive->bitsSize + 7) % 8) * sizeof(unsigned char));
    for (int i = 0; i < (archive->bitsSize + 7) / 8; i++) {
        readChar(&(archive->buffer[i]), buffer, &shift);
    }
}

int findCodeInTable(CompressedHaffmanArchive* archive, const unsigned long long code, const unsigned char codeLength) {
    int ans = -1;
    for (int i = 0; i < 256; i++) {
        if (archive->codeTable.codeLength[i] == codeLength) {
            ans = i;
            for (int j = 0; j < codeLength; j++) {
                int bitTableValue = ((archive->codeTable.code[i] & (1 << (codeLength - j - 1))) >> (codeLength - j - 1));
                int bitValue = ((code & (1 << (j))) >> (j));
                if (bitTableValue != bitValue) {
                    ans = -1;
                    break;
                }
            }
        }
        if (ans != -1) {
            return ans;
        }
    }
    return -1;
}

void decompressArchiveToFile(CompressedHaffmanArchive* archive, const unsigned char* filename) {
    FILE* output = fopen(filename, "wb");
    fclose(output);
    long long code = 0;
    char codeLength = 0;
    for (int i = 0; i < archive->bitsSize; i++) {
        code |= (getBit(archive, i) << codeLength);
        codeLength++;
        int valueInTable = findCodeInTable(archive, code, codeLength);
        if (valueInTable != -1) {
            //printf("Decoded symb: %d\n", valueInTable);
            writeCharToFile(valueInTable, filename);
            code = 0;
            codeLength = 0;
        }
    }
}
