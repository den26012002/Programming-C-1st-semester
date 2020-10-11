#include <stdio.h>
#include "triangle.h"

int main()
{
    Triangle triangle;
    Point apexes[3];
    printf("Enter apexes: \n");
    int i;
    float x, y;
    for (i = 0; i < 3; i++) {
        scanf("%f %f", &x, &y);
        apexes[i] = createPoint(x, y);
    }
    triangle = createTriangleWithPoints(apexes[0], apexes[1], apexes[2]);
    printf("perimeter of the triangle = %f\n", findPerimeter(triangle));
    printf("square of the triangle = %f\n", findSquare(triangle));

    return 0;
}
