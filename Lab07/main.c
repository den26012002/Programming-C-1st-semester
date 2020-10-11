/*Lab #7
  Variant #16*/

#include <stdio.h>
#include <math.h>

enum Press {
    book,
    magazine,
    newspaper,
    booklet,
    textbook,
    atlas,
    anthology
};

typedef struct Circle {
    float x, y;
    float radius;
    float length;
}Circle;

float findCircleLength(float radius) {
    return 2 * acos(-1) * radius;
}

Circle createCircle(float x, float y, float radius) {
    Circle newCircle;
    newCircle.x = x;
    newCircle.y = y;
    newCircle.radius = radius;
    newCircle.length = findCircleLength(radius);
    return newCircle;
}

typedef struct States {
    unsigned int numLock : 1;
    unsigned int capsLock : 1;
    unsigned int scrollLock : 1;
} States;

typedef union KeyBoard {
    int number;
    States states;

} KeyBoard;

int main()
{
    enum Press answer = newspaper;
    printf("%d\n", answer);

    float x, y, radius;
    scanf("%f %f %f", &x, &y, &radius);
    Circle circle;
    circle = createCircle(x, y, radius);
    printf("%f\n", circle.length);

    KeyBoard keyboard;
    scanf("%x", &keyboard.number);
    printf("%d\n", keyboard.states.numLock);
    printf("%d\n", keyboard.states.capsLock);
    printf("%d", keyboard.states.scrollLock);

    return 0;
}

