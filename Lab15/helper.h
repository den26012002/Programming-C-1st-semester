#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

void readInt(unsigned int*, const unsigned char*, unsigned int*);

void readShort(unsigned short*, const unsigned char*, unsigned int*);

void writeIntToFile(unsigned int, const unsigned char*);

void writeShortToFile(unsigned short, const unsigned char*);

int readFileToBuffer(unsigned char**, const unsigned char*);

#endif // HELPER_H_INCLUDED
