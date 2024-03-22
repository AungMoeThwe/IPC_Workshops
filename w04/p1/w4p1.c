/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    int count, iteration;
    char type;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do {
        printf("\nD = do/while | W = while | F = for | Q = quit\nEnter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &type, &iteration);

        if ((type=='D' || type == 'W' || type== 'F') && ((iteration>=3) && (iteration<= 20))) {// CORRECT POSSIBLE COMBINATIONS
            switch (type) 
            {
            case 'D':
                printf("DO-WHILE: ");
                count = 1;
                do {
                    printf("D");
                    count++;
                } while (count < iteration + 1);
                count = 1;
                printf("\n");
                break;
            case 'W':
                count = 1;
                printf("WHILE   : ");
                while (count <= iteration) {
                    printf("W");
                    count++;
                }
                count = 1;
                printf("\n");
                break;
            case 'F':
                printf("FOR     : ");
                for (count = 1; count <= iteration; count++) {
                    printf("F");
                }
                count = 1;
                printf("\n");
                break;
            default:
                break;
            }

        }
        else if (type == 'Q') { // Special Case of Q
            if (iteration != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
            else
            {
                iteration = -100; //flags to stop the loop because the flag condition is set to iteration != -100
            }

        }
        else {
            if ((type == 'D' || type == 'W' || type == 'F') && ((iteration <= 3) || (iteration >= 20)))
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            else
            {
                printf("ERROR: Invalid entered value(s)!\n");
            }
        }
        
    } while (iteration != -100);

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}