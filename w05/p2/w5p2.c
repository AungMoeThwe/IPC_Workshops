/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Aung Moe Thwe
Student ID#: 148396237
Email      : amthwe@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month, day = 1;
    double morning, morningTotal = 0,morningAverage, evening, eveningTotal = 0, eveningAverage, totalCombined, totalAverage;
    int i;

    printf("General Well-being Log\n======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year > MAX_YEAR || year < MIN_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (month < 1 || month > 12)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (year > MAX_YEAR || year < MIN_YEAR || month < JAN || month > DEC); // DO WHILE loop for checking correct month/year

    printf("\n*** Log date set! ***\n");

    for (i = 0; i < LOG_DAYS; i++) //Starts the loop for the number of log days
    {
        

        switch (month)
        {
        case (1):
            printf("\n%d-JAN-%02d\n", year, day);
            break;
        case (2):
            printf("\n%d-FEB-%02d\n", year, day);
            break;
        case (3):
            printf("\n%d-MAR-%02d\n", year, day);
            break;
        case (4):
            printf("\n%d-APR-%02d\n", year, day);
            break;
        case (5):
            printf("\n%d-MAY-%02d\n", year, day);
            break;
        case (6):
            printf("\n%d-JUN-%02d\n", year, day);
            break;
        case (7):
            printf("\n%d-JUL-%02d\n", year, day);
            break;
        case (8):
            printf("\n%d-AUG-%02d\n", year, day);
            break;
        case (9):
            printf("\n%d-SEP-%02d\n", year, day);
            break;
        case (10):
            printf("\n%d-OCT-%02d\n", year, day);
            break;
        case (11):
            printf("\n%d-NOV-%02d\n", year, day);
            break;
        case (12):
            printf("\n%d-DEC-%02d\n", year, day);
            break;
        default:
            break;
        } //Switch case for mapping the number to year without using an array string.

        

        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morning);
            if (morning < 0.0 || morning > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }

        } while (morning < 0.0 || morning > 5.0); // Morning rating test

        morningTotal += morning;
        
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening);
            if (evening < 0.0 || evening > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }

        } while (evening < 0.0 || evening > 5.0); //Evening rating test

        eveningTotal += evening;

        day = day + 1; //for the day to increment one after every successfule morning and evening logs
        
    } // loop for the log days morning evening

    totalCombined = morningTotal + eveningTotal;
    morningAverage = morningTotal / (double)LOG_DAYS;
    eveningAverage = eveningTotal / (double)LOG_DAYS;
    totalAverage = (morningAverage + eveningAverage) / 2;


    // Final To Display the results
    printf("\nSummary\n");
    printf("=======");
    printf("\nMorning total rating: %6.3f", morningTotal);
    printf("\nEvening total rating: %6.3f", eveningTotal);
    printf("\n----------------------------");
    printf("\nOverall total rating: %6.3f", totalCombined);
    printf("\n\nAverage morning rating:  %.1f", morningAverage);
    printf("\nAverage evening rating:  %.1f", eveningAverage);
    printf("\n----------------------------");
    printf("\nAverage overall rating:  %.1lf\n", totalAverage);

    


    return 0;
}