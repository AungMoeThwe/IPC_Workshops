/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    int shirtNum, subTotal, taxes, total; // declare variables as integers so as not to make unexpected results
    double smallPrice, mediumPrice, largePrice; // these are declared as floating points to take user input 
    
    printf("Set Shirt Prices\n");
    printf("================\n");
    
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallPrice);
    
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumPrice);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largePrice);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");

    printf("SMALL  : $%.2lf", smallPrice);
    printf("\n");
    printf("MEDIUM : $%.2lf", mediumPrice);
    printf("\n");
    printf("LARGE  : $%.2lf", largePrice);
    printf("\n\n");

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtNum);
    printf("\n");

    printf("Patty's shopping cart...\n");

    // calculating for final values.
    subTotal = (smallPrice*100) * shirtNum; //did not round off subtotal because we still have to calculate tax
    taxes = (TAX * subTotal) + 0.5; //to round off the tax value to 2 decimal place before .4lf specifier
    total = subTotal + taxes;
    subTotal = subTotal + 0.5; // rounding subtotal after tax calculation. did not round total because subtotal and taxes will already be the rounded values.
   
    printf("Contains : %d shirts", shirtNum);
    printf("\n");
    printf("Sub-total: $");
    printf("%8.4lf", subTotal/(double)100.0);
    printf("\n"); 
    printf("Taxes    : $");
    printf("%8.4lf", taxes/(double)100.0);
    printf("\n");
    printf("Total    : $");
    printf("%8.4lf\n", total/(double)100.0);
    
    return 0;
}