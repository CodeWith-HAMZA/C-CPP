// Display Month by Month Calendar for a Given Year
// IDE: Code::Blocks - C Programming

// Header File

#include <stdio.h>
#include<conio.h>
#define SAMPLE_YEAR 2023

void lim(int min, int max, int *current);

// Function it returns the index of the day for date DD/MM/YYYY
int day_number(int day, int month, int year)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

// Function it returns the name of the month for the given month Number

// Example: January - 0, February - 1 and so on

char *get_month_name(int month_number)
{
    char *month;

    switch (month_number)
    {

    case 0:
        month = "January";
        break;

    case 1:
        month = "February";
        break;

    case 2:
        month = "March";
        break;

    case 3:
        month = "April";
        break;

    case 4:
        month = "May";
        break;

    case 5:
        month = "June";
        break;

    case 6:
        month = "July";
        break;

    case 7:
        month = "August";
        break;
    case 8:
        month = "September";
        break;
    case 9:
        month = "October";
        break;
    case 10:
        month = "November";
        break;
    case 11:
        month = "December";
        break;
    }
    return month;
}

// Function to return the number of days in a month, 
// ***! -> (It Could Be Further Improved By Using [Arrays-And-Loops], For Now Keeping Things Quite Simple)
int number_of_days(int month_number, int year)
{
    // January
    if (month_number == 0)
        return (31);

    // February
    if (month_number == 1)
    {
        // If the year is leap then Feb has 29 days
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        return (28);
    }

    // March
    if (month_number == 2)
        return (31);

    // April

    if (month_number == 3)
        return (30);

    // May

    if (month_number == 4)
        return (31);

    // June
    if (month_number == 5)
        return (30);

    // July
    if (month_number == 6)
        return (31);

    // August
    if (month_number == 7)
        return (31);

    // September
    if (month_number == 8)
        return (30);

    // October
    if (month_number == 9)
        return (31);

    // November
    if (month_number == 10)
        return (30);

    // December
    if (month_number == 11)
        return (31);
}

// Function to print the clendar of the given year

void print_calendar(int year, int monthNumber, int givenDayPosition,int  givenDatePosition)
    // Index of the day from 0 to 6 
{ 
    int days; // Number Of Days
    int current = day_number(givenDayPosition, 1, SAMPLE_YEAR); // * current day
    int k, j; // * For Looping


    
    // i for Iterate through months j for Iterate through days of the month - i

     


        days = number_of_days(monthNumber, year);

        // Print the current month name

        printf("\n ------------%s-------------\n", get_month_name(monthNumber));

        // Print the columns

        printf(" Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print spaces

        

        for (k = 0; k < current; k++)

            printf("     ");

        for ( j = givenDatePosition; j <= days; j++)

        {

            printf("%5d", j);

            if (++k > 6)

            {

                k = 0;

                printf("\n");
            }
        }

        if (k)

	    printf("\n");

	current = k;


    return;
}

// Main Function

int main()

{

    int year, month, day, date, i=0;

    clrscr();    // * Turn On For Turbo-Compiler Only
    printf("Enter the Year: ");
    scanf("%d", &year);
    printf("Enter the Month: ");
    lim(1, 12, &month);
    printf("Enter The Day: ");
    lim(1, 7, &day);

    printf("Enter The Date: ");
     lim(1, 31, &date);
    clrscr();
    gotoxy(4, 40);
    printf("  Calendar - %d", year);

    // * Show If Leap-Year
    if (year % 4 == 0 ) printf(" (Leap Year)\n\n");
    else printf("\n\n");


    // * How Many Months To Be Printed Depends On The Loop, Currently Printing Just (Two-Months)
    for( i=0; i<=1; i++){
	// * Handling Circular-Increment
	if( month == 12){

	    if(i==0) print_calendar(year, month-1+i, day, date);
	    else print_calendar(year, i-1, day, date);

	}else print_calendar(year, month-1+i, day, date );

    }

     getch(); // * Turn On For Turbo-Compiler Only
    return 0;
}

void lim(int min, int max, int *current){
    scanf("%d", current);
    if(min <= *current && max >= *current)
	return;

    printf("Sorry, Value Not Acceptable ;(\nTry Again :> ");
    lim(min, max, current);
}
