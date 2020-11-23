#include "frameV2.h"

void readFrameV2(FrameV2* frame, const unsigned char* buffer, int* shift) {
    for (int i = 0; i < 3; i++) {
        /*if (buffer[*shift] == 13) {
            printf("I'm here!\n");
            frame->identifier[i] = ' ';
            continue;
        }*/
        frame->identifier[i] = buffer[*shift];
        (*shift)++;
    }
    frame->identifier[3] = '\0';
    frame->size = 0;
    for (int i = 0; i < 3; i++) {
        frame->size <<= 8;
        //printf("%d ", buffer[*shift]);
        frame->size += buffer[*shift];
        (*shift)++;
    }
    frame->value = malloc(frame->size * sizeof(char));
    int iAdd = 0;
    frame->textEncoding = 0;
    if (frame->identifier[0] == 'T' || frame->identifier[0] == 'C') {
        iAdd = 1;
        frame->textEncoding = buffer[*shift];
        (*shift)++;
    }
    for (int i = 0; i < frame->size - iAdd; i++) {
        frame->value[i] = buffer[*shift];
        (*shift)++;
    }
}
