#include <math.h>
#include "triangle.h"

Point createPoint(float x, float y) {
    Point result;
    result.x = x;
    result.y = y;
    return result;
}

Triangle createTriangleWithPoints(Point a, Point b, Point c) {
    Triangle result;
    result.a = a;
    result.b = b;
    result.c = c;
    return result;
}

Triangle createTriangleWithCoordinates(float x1, float y1, float x2, float y2, float x3, float y3) {
    Point a = createPoint(x1, y1);
    Point b = createPoint(x2, y2);
    Point c = createPoint(x3, y3);
    return createTriangleWithPoints(a, b, c);
}

float findLengthWithPoints(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

float findLengthWithCoordinates(float x1, float y1, float x2, float y2) {
    Point a = createPoint(x1, y1);
    Point b = createPoint(x2, y2);
    return findLengthWithPoints(a, b);
}

float findPerimeter(Triangle triangle) {
    float abLength = findLengthWithPoints(triangle.a, triangle.b);
    float bcLength = findLengthWithPoints(triangle.b, triangle.c);
    float acLength = findLengthWithPoints(triangle.a, triangle.c);
    return abLength + bcLength + acLength;
}

float findSquare(Triangle triangle) {
    float semiperimeter = findPerimeter(triangle) / 2;
    float abLength = findLengthWithPoints(triangle.a, triangle.b);
    float bcLength = findLengthWithPoints(triangle.b, triangle.c);
    float acLength = findLengthWithPoints(triangle.a, triangle.c);
    return pow(semiperimeter * (semiperimeter - abLength) * (semiperimeter - bcLength) * (semiperimeter - acLength), 0.5);
}
