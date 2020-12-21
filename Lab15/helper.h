#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

void readInt(unsigned int*, const unsigned char*, unsigned int*);

void readShort(unsigned short*, const unsigned char*, unsigned int*);

void readLongLong(unsigned long long*, const unsigned char*, unsigned int*);

void readChar(unsigned char*, const unsigned char*, unsigned int*);

void writeIntToFile(unsigned int, const unsigned char*);

void writeShortToFile(unsigned short, const unsigned char*);

void writeLongLongToFile(unsigned long long, const unsigned char*);

void writeCharToFile(unsigned char, const unsigned char*);

int readFileToBuffer(unsigned char**, const unsigned char*);

void swapI(unsigned int*, unsigned int*);

void swapC(unsigned char*, unsigned char*);

#endif // HELPER_H_INCLUDED
