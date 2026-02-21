#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month (already converted to day of year)
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
    int leap = 0;

    /* Correct leap year logic */
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leap = 1;

    if (leap)
    {
        /* If leap year and after Feb 28, add 1 day */
        if (month > 2)
            day++;

        printf("Day of the year: %d\n", day);
        printf("Remaining days: %d\n", 366 - day);
    }
    else
    {
        /* If not leap year but Feb 29 exists -> invalid */
        if (month == 2 && day == 60)
        {
            printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
            return;
        }

        printf("Day of the year: %d\n", day);
        printf("Remaining days: %d\n", 365 - day);
    }
}