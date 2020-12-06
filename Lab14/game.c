#include <string.h>
#include "game.h"
#include "helper.h"

void play(const BMP* bmp, const char* outputDir, const int maxIter, const int dumpFreq) {
    BMP* generation = malloc(sizeof(BMP));
    copyBMP(generation, bmp);
    for (int i = 1; i <= maxIter; i++) {
        char* realFileWay = malloc((strlen(outputDir) + 20) * sizeof(char));
        int shift = 0;
        for (int j = 0; j < strlen(outputDir); j++) {
            realFileWay[shift++] = outputDir[j];
        }
        char* g = "\\generation";
        for (int j = 0; j < 11; j++) {
            realFileWay[shift++] = g[j];
        }
        for (int j = 3; j >= 0; j--) {
            realFileWay[shift++] = (char)((int)(((int)(i / pow(10, j)) % 10) + (int)'0'));
        }
        //printf("\n");
        char* bmp = ".bmp";
        for (int j = 0; j < 4; j++) {
            realFileWay[shift++] = bmp[j];
        }
        realFileWay[strlen(outputDir) + 19] = '\0';
        if (i % dumpFreq == 0) {
            writeBMPToFile(generation, realFileWay);
        }
        nextGeneration(generation);
    }
}

void nextGeneration(BMP* generation) {
    const int MOVES[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
    PixelsArray* array = malloc(sizeof(PixelsArray));
    copyPixelsArray(array, &(generation->pixelsArray));
    int pixelsWidth = generation->info.pixelsWidth;
    int pixelsHeight = generation->info.pixelsHeight;
    int sum = 0;
    for (int x = 0; x < pixelsWidth; x++) {
        for (int y = 0; y < pixelsHeight; y++) {
            sum = 8;
            for (int i = 0; i < 8; i++) {
                int newX = (x + MOVES[i][0]);
                if (newX < 0) {
                    newX += pixelsWidth;
                }
                if (newX >= pixelsWidth) {
                    newX -= pixelsWidth;
                }
                int newY = (y + MOVES[i][1]);
                if (newY < 0) {
                    newY += pixelsHeight;
                }
                if (newY >= pixelsHeight) {
                    newY -= pixelsHeight;
                }
                sum -= getPixel(&(generation->pixelsArray), newX, newY);
                //printf("%d ", sum);
            }
            if (sum < 2 || sum > 3) {
                setPixel(array, x, y, 1);
            }
            else if (sum == 3) {
                setPixel(array, x, y, 0);
            }
        }
    }
    free(generation->pixelsArray.array);
    generation->pixelsArray.array = array->array;
}
