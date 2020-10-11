/*Lab #8
  Variant #16*/

#include <stdio.h>
#include <string.h>

/*typedef struct String {
    char *string;
    int size;
} String;*/

int main()
{
    char str1[1000];
    char str2[1000];
    int n;
    scanf("%s %s %d", str1, str2, &n);
    strncat(str1, str2, n);
    printf("%s\n", str1);

    scanf("%s %s", str1, str2);
    int cmpResult = strcmp(str1, str2);
    printf("%d\n", cmpResult);

    scanf("%s %s %d", str1, str2, &n);
    strncpy(str2, str1, n);
    printf("%s\n", str2);

    char symbolForSearch;
    scanf("%s %c", str1, &symbolForSearch);
    char *answer = strrchr(str1, symbolForSearch);
    if (answer == 0) {
        printf("Not found\n");
    } else {
        printf("%d\n", answer - str1 + 1);
    }

    scanf("%s %s", str1, str2);
    int length = strcspn(str1, str2);
    printf("%d", length);

    return 0;
}
