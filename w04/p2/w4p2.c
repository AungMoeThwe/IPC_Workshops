/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Aung Moe Thwe
Student ID#: 148396237
Email      : amthwe@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int shopping;
    char flag = 'Y';
        
        while (flag != 'N')
        {
        int apples, oranges, pears, tomatoes, cabbages;
        int pick;

        printf("Grocery Shopping\n================");

        printf("\nHow many APPLES do you need? : ");
        scanf(" %d", &apples);
        if (apples < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many APPLES do you need? : ");
            scanf(" %d", &apples);
        }


        printf("\nHow many ORANGES do you need? : ");
        scanf(" %d", &oranges);
        if (oranges < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many ORANGES do you need? : ");
            scanf(" %d", &oranges);
        }

        printf("\nHow many PEARS do you need? : ");
        scanf(" %d", &pears);
        if (pears < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many PEARS do you need? : ");
            scanf(" %d", &pears);
        }

        printf("\nHow many TOMATOES do you need? : ");
        scanf(" %d", &tomatoes);
        if (tomatoes < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many TOMATOES do you need? : ");
            scanf(" %d", &tomatoes);
        }

        printf("\nHow many CABBAGES do you need? : ");
        scanf(" %d", &cabbages);
        if (cabbages < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many CABBAGES do you need? : ");
            scanf(" %d", &cabbages);
        }

        printf("\n--------------------------\nTime to pick the products!\n--------------------------\n\n");

        while (apples != 0) //apples 
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf(" %d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick == apples) {
                apples = apples - pick;
                printf("Great, that's the apples done!\n\n");
            }
            else if (pick > 0 && pick < apples) {
                apples = apples - pick;
                printf("Looks like we still need some APPLES...\n");
            }
            else if (pick > apples) {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
            }
        }


        while (oranges != 0) //oranges 
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf(" %d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick == oranges) {
                oranges = oranges - pick;
                printf("Great, that's the oranges done!\n\n");
            }
            else if (pick > 0 && pick < oranges) {
                oranges = oranges - pick;
                printf("Looks like we still need some ORANGES...\n");
            }
            else if (pick > oranges) {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            }
        } 


        while (pears != 0) //PEARS
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf(" %d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick == pears) {
                pears = pears - pick;
                printf("Great, that's the pears done!\n\n");
            }
            else if (pick > 0 && pick < pears) {
                pears = pears - pick;
                printf("Looks like we still need some PEARS...\n");
            }
            else if (pick > pears) {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
            }
        } 


        while (tomatoes != 0) //tomatoes
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf(" %d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick == tomatoes) {
                tomatoes = tomatoes - pick;
                printf("Great, that's the tomatoes done!\n\n");
            }
            else if (pick > 0 && pick < tomatoes) {
                tomatoes = tomatoes - pick;
                printf("Looks like we still need some TOMATOES...\n");
            }
            else if (pick > tomatoes) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
            }
        } 


        while (cabbages != 0) //CABBAGES
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf(" %d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick == cabbages) {
                cabbages = cabbages - pick;
                printf("Great, that's the cabbages done!\n\n");
            }
            else if (pick > 0 && pick < cabbages) {
                cabbages = cabbages - pick;
                printf("Looks like we still need some CABBAGES...\n");
            }
            else if (pick > cabbages) {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
            }
        } 

        printf("All the items are picked!\n");
        printf("\nDo another shopping? (0=NO): ");
        scanf(" %d", &shopping);
        printf("\n");
        

        if (shopping == 0) {
            flag = 'N';
            printf("Your tasks are done for today - enjoy your free time!\n");
        }

        }
    

    

    
    

    return 0;
}


