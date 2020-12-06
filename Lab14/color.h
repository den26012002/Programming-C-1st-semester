#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

void readColor(Color*, unsigned char*, unsigned int*);

void writeColorToFile(const Color*, const unsigned char*);

void copyColor(Color*, const Color*);

#endif // COLOR_H_INCLUDED
