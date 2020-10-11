/*Lab #4
  Variant #16*/

#include <stdio.h>
#include <stdbool.h>

int isMoreOrEquals(int x, int divider) {
	return (int)(bool)(int)((double)x / (double)divider);
}

int main()
{
    int x;
	scanf("%d", &x);
	const char *answers[2] = {"No", "Yes"};
	printf("%s", answers[isMoreOrEquals(x, 21) - isMoreOrEquals(x, 46)]);

	scanf("%d", &x);
	printf("%d", (x >> 15) & 1);


    return 0;
}
