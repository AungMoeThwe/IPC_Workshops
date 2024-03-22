/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffeeStrength1, cream1, coffeeStrength2, cream2, coffeeStrength3, cream3;
    char  strengthPref, creamPref;
    int servingPref;
    int weight1, weight2, weight3;

    printf("Take a Break - Coffee Shop\n==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &coffeeStrength1);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &coffeeStrength2);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &coffeeStrength3);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &cream3);

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeeStrength1== 'L' || coffeeStrength1=='l'), (coffeeStrength1=='M' || coffeeStrength1=='m'), (coffeeStrength1=='R' || coffeeStrength1=='r'),weight1, weight1 / GRAMS_IN_LBS, (cream1=='Y' || cream1=='y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeeStrength2 == 'L' || coffeeStrength2 == 'l'), (coffeeStrength2 == 'M' || coffeeStrength2 == 'm'), (coffeeStrength2 == 'R' || coffeeStrength2 == 'r'), weight2, weight2 / GRAMS_IN_LBS, (cream2 == 'Y' || cream2 == 'y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffeeStrength3 == 'L' || coffeeStrength3 == 'l'), (coffeeStrength3 == 'M' || coffeeStrength3 == 'm'), (coffeeStrength3 == 'R' || coffeeStrength3 == 'r'), weight3, weight3 / GRAMS_IN_LBS, (cream3 == 'Y' || cream3 == 'y'));
    

    // TABLEPREF1
    printf("\nEnter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf("%c%*c", &strengthPref);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &creamPref);
    printf("Typical number of daily servings: ");
    scanf("%i%*c", &servingPref);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n", (strengthPref=='L' || strengthPref=='l'), (servingPref<=4), (creamPref=='Y' || creamPref=='y'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (strengthPref == 'R' || strengthPref == 'r'), (servingPref >= 5 && servingPref<= 9), (creamPref == 'N' || creamPref == 'n'));
    printf(" 3|       %d         |      %d      |   %d   |\n", (strengthPref == 'm' || strengthPref == 'M'), (servingPref >=10), (creamPref == 'N' || creamPref == 'n'));


    //TABLEPREF2
    printf("\nEnter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf("%c%*c", &strengthPref);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &creamPref);
    printf("Typical number of daily servings: ");
    scanf("%i%*c", &servingPref);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n", (strengthPref == 'L' || strengthPref=='l'), (servingPref < 4 || servingPref==4), (creamPref=='Y' || creamPref == 'y'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (strengthPref == 'R' || strengthPref == 'r'), (servingPref >= 5 && servingPref <= 9), (creamPref == 'N' || creamPref == 'n'));
    printf(" 3|       %d         |      %d      |   %d   |\n", (strengthPref == 'm' || strengthPref == 'M'), (servingPref >= 10), (creamPref == 'N' || creamPref == 'n'));

    printf("\nHope you found a product that suits your likes!\n");


    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/