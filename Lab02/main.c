/*Lab #2
  Variant #16*/

#include <stdio.h>
#include <math.h>

const char ERROR_ROOTING_MESSAGE[] = "Error! (Rooting negative number)";
const char ERROR_DIVISION_ZERO_MESSAGE[] = "Error! (Division by zero)";

void z1(float x) {
    if (x * x - 9 < 0) {
        printf("%s", ERROR_ROOTING_MESSAGE);
    }
    else if (x * x - 2 * x - 3 + (x + 1) * sqrt(x * x - 9) == 0) {
        printf("%s", ERROR_DIVISION_ZERO_MESSAGE);
    }
    else {
        printf("z1 = %f\n", (x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9)) / (x * x - 2 * x - 3 + (x + 1) * sqrt(x * x - 9)));
    }
}

void z2(float x) {
    if (x - 3 == 0) {
        printf("%s", ERROR_DIVISION_ZERO_MESSAGE);
    }
    else if ((x + 3) / (x - 3) < 0) {
        printf("%s", ERROR_ROOTING_MESSAGE);
    }
    else {
        printf("z2 = %f\n", sqrt((x + 3) / (x - 3)));
    }
}

int main()
{
    float x;
    scanf("%f", &x);
    z1(x);

    scanf("%f", &x);
    z2(x);

    return 0;
}
