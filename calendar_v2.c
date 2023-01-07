
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define numberOfMonths (int)12
int printCalendar(int, int, int );
int getNumberOfDatesThroughMonth(int , int );


typedef struct Month
{
    int numberOfDaysInMonth;
    char *monthName;
} Month;

const Month mon[numberOfMonths] = {
    {
        .numberOfDaysInMonth = 31,
        .monthName = (char *)"JANUARY",
    },
    {
        .numberOfDaysInMonth = 28,
        .monthName = (char *)"FEBRUARY",
    },
    {
        .numberOfDaysInMonth = 31,
        .monthName = (char *)"MARCH",
    },
    {
        .numberOfDaysInMonth = 30,
        .monthName = (char *)"APRIL",
    },
    {
        .numberOfDaysInMonth = 31,
        .monthName = (char *)"MAY",
    },
    {
        .numberOfDaysInMonth = 30,
        .monthName = (char *)"JUNE",
    },
    {
        .numberOfDaysInMonth = 31,
        .monthName = (char *)"JULY",
    },
    {
        .numberOfDaysInMonth = 31,
        .monthName = (char *)"AUGUST",
    },
    {
        .numberOfDaysInMonth = 30,
        .monthName = (char *)"SEPTEMBER",
    },
    {
        .numberOfDaysInMonth = 31,
        .monthName = (char *)"OCTOBER",
    },
    {
        .numberOfDaysInMonth = 30,
        .monthName = (char *)"NOVEMBER",
    },
    {
        .numberOfDaysInMonth = 31,
        .monthName = (char *)"DECEMBER",
    }};

int getNumberOfDatesThroughMonth(int givenYear, int givenMonthNumber)
{
    for (int i = 0; i < sizeof(mon) / sizeof(Month); i++)
        if (givenMonthNumber == i)
            return givenYear % 4 == 0 && i == 1 ? (mon[i].numberOfDaysInMonth + 1) : (mon[i].numberOfDaysInMonth);
    return -1;
}

void main()
{
    int i, j, dayNumber, totalDates, initialDate = 1, MonthNumber, year;
    // clrscr();
    printf("C Program to Print a Calendar With Start With Input Day\n\n");

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter Month: ");
    scanf("%d", &MonthNumber);

    printf("Enter Initial-Date: ");
    scanf("%d", &initialDate);

    printf("\nEnter Day 0-6 (Mon-Sun): ");
    scanf("%d", &dayNumber);

    printf("\n%d---[%s] \n", year, mon[MonthNumber].monthName);
    dayNumber = printCalendar(dayNumber, getNumberOfDatesThroughMonth(year, MonthNumber), initialDate) % 7;

    printf("\n\n");
    printf("\n%d---[%s] \n", year, mon[MonthNumber + 1].monthName);
    printCalendar(dayNumber, getNumberOfDatesThroughMonth(year, ++MonthNumber), 1);

    getch();
}

int printCalendar(int dayNumber, int totalDates, int initialDate)
{
    int j = 0;
    printf("___________________________________________________");
    printf("\nMon \tTue \tWed \tThu \tFri \tSat \tSun \n");
    printf("---------------------------------------------------\n\n");

    for (j = dayNumber; j > 0; j--)
        printf("\t");
    while (initialDate <= totalDates)
    {
        if (!(dayNumber == 0))
            if (dayNumber % 7 == 0)
                printf("\n");

        printf("%d\t", initialDate);

        ++initialDate;
        ++dayNumber;
    }

    return dayNumber;
}
