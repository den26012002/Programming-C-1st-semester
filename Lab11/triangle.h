#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

typedef struct Point {
    float x, y;
} Point;

typedef struct Triangle {
    Point a, b, c;
} Triangle;

Point createPoint(float x, float y);

Triangle createTriangleWithPoints(Point a, Point b, Point c);

Triangle createTriangleWithCoordinates(float x1, float y1, float x2, float y2, float x3, float y3);

float findLengthWithPoints(Point a, Point b);

float findLengthWithCoordinates(float x1, float y1, float x2, float y2);

float findPerimeter(Triangle triangle);

float findSquare(Triangle triangle);



#endif /* TRIANGLE_H_INCLUDED */
