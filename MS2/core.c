/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include"core.h"

//strlen, strcpy, strcat, strcmp, strncat, strncmp, strncpy, strchr, strrchr

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// Gets an integer from keyboard
int inputInt(void)
{
    char newLine;
    int val;
    do
    {
        scanf("%d%c", &val, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (newLine != '\n');
    return val;
}

// Similar to inputInt but validates for positive, gurantees positive
int inputIntPositive(void)
{
    int val;
    do
    {
        val = inputInt();
        if (val < 1)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (val < 1);
    return val;
}

// Similar to inputInt but validates the value entered is between the limits
int inputIntRange(int lowerLimit, int upperLimit)
{
    int val;
    do
    {
        val = inputInt();
        if (val > upperLimit || val < lowerLimit)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerLimit, upperLimit);
        }
    } while ((val > upperLimit || val < lowerLimit));
    return val;
}

// Returns a character value
char inputCharOption(const char* charList)
{
    char inputChar;
    int i, match;

    do
    {
        i = 0, match = 0;
        inputChar = getchar();
        do
        {
            if (inputChar == *(charList + i))
            {
                match = 1; //indicates that there is a match in the array
            }
            i++;
        } while (match != 1 && *(charList + i) != '\0'); //loops until the end of the character array to ensure the letter is there.

        if (match == 0)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", charList);

        }

    } while (match == 0);
    return inputChar;
}

// Obtain user input for C string value with length depending on range
void inputCString(char* cString, int minChar, int maxChar) {
    char input[100] = { '\0' };
    int length;

    do {
        // Prompt user for input
        fgets(input, sizeof(input), stdin);

        // Calculate the length of the input while removing the newline character if present
        length = strlen(input);
        if (input[length - 1] == '\n') {
            input[--length] = '\0'; // Reduce length and remove newline
        }
        else {
            // If newline is not at the end, input may be too long and buffer needs to be cleared
            clearInputBuffer();
        }

        // Validate string length and provide error messages if necessary
        if ((minChar == maxChar) && (length != minChar)) {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
        }
        else if (length < minChar) {
            printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
        }
        else if (length > maxChar) {
            printf("ERROR: String length must be no more than %d chars: ", maxChar);
        }

    } while (length < minChar || length > maxChar);

    // Copy the validated and trimmed input to the target string
    strcpy(cString, input);
}



void displayFormattedPhone(const char* phNum)
{
    int check = 0, count = 0;
    if (phNum != NULL)
    {
        while (*(phNum + count) != '\0')
        {
            if ((int)*(phNum + check) > 47 && (int)*(phNum + check) < 58)
            {
                check++; // loop through the array in order to ensure its between 0(ASCII code for  and 9)
            }
            count++;
        }

        if (check == 10)
        {
            check = 0;
            char open = '(', close = ')', dash = '-';
            while (*(phNum + check) != '\0')
            {
                if (check == 0)
                {
                    printf("%c", open);
                }
                else if (check == 3)
                {
                    printf("%c", close);
                }
                else if (check == 6)
                {
                    printf("%c", dash);
                }
                printf("%c", *(phNum + check));
                check++;
            }
        }
    }
    if (check != 10)
    {
        printf("(___)___-____");
    }

}

