/*Lab #10
  Variant #16*/

#include <stdio.h>

int gcd(int a, int b) {
    while (a * b > 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

typedef struct MyArray {
    int *array;
    int size;
} MyArray;

MyArray createAnArray(int n) {
    MyArray ans;
    ans.size = 0;
    while (n > 0) {
        ans.array[ans.size] = n % 10;
        ans.size++;
        n /= 10;
    }
    return ans;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("gcd = %d\n", gcd(a, b));
    printf("lcm = %d\n", lcm(a, b));

    int n;
    scanf("%d", &n);
    MyArray resultArray = createAnArray(n);
    for (int i = 0; i < resultArray.size; i++) {
        printf("%d ", resultArray.array[i]);
    }

    return 0;
}
