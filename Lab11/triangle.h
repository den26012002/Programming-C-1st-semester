#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

typedef struct Point {
    float x, y;
} Point;

typedef struct Triangle {
    Point a, b, c;
} Triangle;

void createPoint(Point* point, float x, float y);

void createTriangleWithPoints(Triangle* triangle, Point* a, Point* b, Point* c);

void createTriangleWithCoordinates(Triangle* triangle, float x1, float y1, float x2, float y2, float x3, float y3);

float findLengthWithPoints(Point* a, Point* b);

float findLengthWithCoordinates(float x1, float y1, float x2, float y2);

float findPerimeter(const Triangle* triangle);

float findSquare(const Triangle* triangle);




#endif /* TRIANGLE_H_INCLUDED */
