/*Lab #9
  Variant #16*/

#include <stdio.h>

char *nameOfDigit(int digit) {
    switch(digit) {
        case 0: return "Zero";
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return "Enter is not a digit";
    }
}

int main()
{
    char str[1000];
    scanf("%s", str);
    int cntDigits = 0;
    int cntUpperCase = 0;
    int cntLowerCase = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            cntDigits++;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            cntUpperCase++;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            cntLowerCase++;
        }
    }
    printf("digits: %d\n", cntDigits);
    printf("upper case letters: %d\n", cntUpperCase);
    printf("lower case letters: %d\n", cntLowerCase);

    int digit;
    scanf("%d", &digit);
    printf("%s", nameOfDigit(digit));


    return 0;
}
