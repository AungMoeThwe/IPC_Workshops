/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

#include <stdio.h>
#include <string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

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


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

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
char inputCharOption(const char* charList) {
    char inputChar, nextChar;
    int i, match = 0, validInput = 1;

    do {
        inputChar = getchar(); // Get the first character of input
        nextChar = getchar(); // Attempt to read the newline character

        // Check if the input is a single character followed by a newline
        if (inputChar != '\n' && nextChar == '\n') {
            // Reset flags for each attempt
            i = 0, match = 0, validInput = 1;

            // Loop through the character list to find a match
            while (*(charList + i) != '\0' && !match) {
                if (inputChar == *(charList + i)) {
                    match = 1; // Match found
                }
                i++;
            }
        }
        else {
            validInput = 0; // Not a single character input
            clearInputBuffer(); // Clear the buffer to remove leftover input
        }

        // Handle invalid input: either not a single char or not in the list
        if (!match || !validInput) {
            printf("ERROR: Character must be one of [%s]: ", charList);
        }

    } while (!match || !validInput);
    
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
            printf("Invalid %d-digit number! Number: ", minChar);
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



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

