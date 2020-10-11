/*Lab #5
  Variant #16*/

#include <stdio.h>

int main()
{
    int array[6] = {34, 45, 56, 67, 78, 89};
    for (int i = 0; i < 6; i++) {
        printf("%d | %d\n", i, array[i]);
    }

    int matrix1[2][2] = {{2, 1}, {1, 3}};
    int matrix2[2][2] = {{1, 2}, {3, 1}};
    int resultMatrix[2][2] = {{0, 0}, {0, 0}};
    int j;
    int k;
    for (int i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
