#ifndef FLAGS_H_INCLUDED
#define FLAGS_H_INCLUDED
#pragma pack(1)

typedef struct FlagsBits {
    unsigned int : 5;
    unsigned int c : 1;
    unsigned int b : 1;
    unsigned int a : 1;
} FlagsBits;

typedef union Flags {
    char value;
    FlagsBits flags;
} Flags;

#pragma pack()
#endif // FLAGS_H_INCLUDED
