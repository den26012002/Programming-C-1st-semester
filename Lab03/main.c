/*Lab #3
  Variant #16*/

#include <stdio.h>

int main()
{
    int number1;
    scanf("%o", &number1);

    printf("%d\n", number1);

    printf("%x\n", number1);
    printf("%x\n", number1 >> 4);

    printf("%x\n", number1);
    printf("%x\n", ~number1);

    int number2;
    scanf("%x", &number2);
    int res = number1 & number2;
    printf("%x", res);

    return 0;
}
