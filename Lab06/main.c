/*Lab #6
  Variant #16*/

#include <stdio.h>
#include <malloc.h>

int main()
{
    float array = {-3.4, 4.5, -5.6, 6.7};
    /*array[0] = -3.4;
    array[1] = 4.5;
    array[2] = -5.6;
    array[3] = 6.7;*/
    int i;
    for (i = 0; i < 4; i++) {
        printf("%d | %.1f\n", i, *(&array + i));
    }

    float *array2;
    array2 = (int*)malloc(4 * sizeof(int));
    array2[0] = -3.4;
    array2[1] = 4.5;
    array2[2] = -5.6;
    array2[3] = 6.7;
    for (i = 0; i < 4; i++) {
        printf("%d | %.1f\n", i, array2[i]);
    }
    free(array2);

    return 0;
}
