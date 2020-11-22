#include <math.h>
#include "triangle.h"

void createPoint(Point* point, float x, float y) {
    point->x = x;
    point->y = y;
}

void createTriangleWithPoints(Triangle* triangle, Point* a, Point* b, Point* c) {
    triangle->a = *a;
    triangle->b = *b;
    triangle->c = *c;
}

void createTriangleWithCoordinates(Triangle* triangle, float x1, float y1, float x2, float y2, float x3, float y3) {
    Point* a;
    createPoint(a, x1, y1);
    Point* b;
    createPoint(b, x2, y2);
    Point* c;
    createPoint(c, x3, y3);
    createTriangleWithPoints(triangle, a, b, c);
    free(a);
    free(b);
    free(c);
}

float findLengthWithPoints(Point* a, Point* b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

float findLengthWithCoordinates(float x1, float y1, float x2, float y2) {
    Point* a;
    createPoint(a, x1, y1);
    Point* b;
    createPoint(b, x2, y2);
    int ans = findLengthWithPoints(a, b);
    free(a);
    free(b);
    return ans;
}

float findPerimeter(const Triangle* triangle) {
    float abLength = findLengthWithPoints(&triangle->a, &triangle->b);
    float bcLength = findLengthWithPoints(&triangle->b, &triangle->c);
    float acLength = findLengthWithPoints(&triangle->a, &triangle->c);
    return abLength + bcLength + acLength;
}

float findSquare(const Triangle* triangle) {
    float semiperimeter = findPerimeter(triangle) / 2;
    float abLength = findLengthWithPoints(&triangle->a, &triangle->b);
    float bcLength = findLengthWithPoints(&triangle->b, &triangle->c);
    float acLength = findLengthWithPoints(&triangle->a, &triangle->c);
    return pow(semiperimeter * (semiperimeter - abLength) * (semiperimeter - bcLength) * (semiperimeter - acLength), 0.5);
}
