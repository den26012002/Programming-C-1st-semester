#include <stdio.h>
#include <time.h>

void findNextDate(int *mDay, int *month, int *year) {
    (*mDay)++;
    int maxMonthDay;
    switch (*month) {
        case 1:
            maxMonthDay = 31;
            break;
        case 2:
            if (*year % 4 == 0 && *year % 400 != 0) {
                maxMonthDay = 29;
            }
            else {
                maxMonthDay = 28;
            }
            break;
        case 3:
            maxMonthDay = 31;
            break;
        case 4:
            maxMonthDay = 30;
            break;
        case 5:
            maxMonthDay = 31;
            break;
        case 6:
            maxMonthDay = 30;
            break;
        case 7:
            maxMonthDay = 31;
            break;
        case 8:
            maxMonthDay = 31;
            break;
        case 9:
            maxMonthDay = 30;
            break;
        case 10:
            maxMonthDay = 31;
            break;
        case 11:
            maxMonthDay = 30;
            break;
        case 12:
            maxMonthDay = 31;
            break;
        default:
            break;
    }
    if (*mDay > maxMonthDay) {
        *mDay = 1;
        (*month)++;
    }
    if (*month > 12) {
        *month = 1;
        (*year)++;
    }
}

int main()
{
    FILE *output;
    char fileName[] = "output.txt";
    if (output == NULL) {
        printf("Error: file wasn't opened");
        return 0;
    }
    output = fopen(fileName, "w+");
    time_t timeNow = time(NULL);
    struct tm *dateNow = localtime(&timeNow);
    int mDay = dateNow->tm_mday;
    int month = 1 + dateNow->tm_mon;
    int year = 1900 + dateNow->tm_year;
    for (int i = 0; i < 10; i++) {
        fprintf(output, "%d%d.%d%d.%d\n", mDay / 10, mDay % 10, month / 10, month % 10, year);
        findNextDate(&mDay, &month, &year);
    }
    fclose(output);

    return 0;
}
