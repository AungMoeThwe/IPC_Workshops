/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    
    int shirtNumPatty, subTotalPatty, taxesPatty, totalPatty; // declaring variables for patty
    int shirtNumTom, subTotalTom, taxesTom, totalTom; // declaring variables for tom
    int shirtNumSal, subTotalSal, taxesSal, totalSal; // declaring variables for sal
    double smallPrice, mediumPrice, largePrice; // these are declared as floating points to take user input 
    int subTotalFinal, taxesFinal, totalFinal; // final values

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
    scanf("%d", &shirtNumPatty);
    printf("\n");

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &shirtNumTom);
    printf("\n");

    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &shirtNumSal);
    printf("\n");

    //calculation for the data
    subTotalPatty = (smallPrice * 100) * shirtNumPatty;
    taxesPatty = (TAX * subTotalPatty) + 0.5;
    totalPatty = subTotalPatty + taxesPatty;
    subTotalPatty = subTotalPatty + 0.5;

    subTotalSal = (mediumPrice * 100) * shirtNumSal;
    taxesSal = (TAX * subTotalSal) + 0.5;
    totalSal = subTotalSal + taxesSal;
    subTotalSal = subTotalSal + 0.5;

    subTotalTom = (largePrice * 100) * shirtNumTom;
    taxesTom = (TAX * subTotalTom) + 0.5;
    totalTom = subTotalTom + taxesTom;
    subTotalTom = subTotalTom + 0.5;

    subTotalFinal = subTotalPatty + subTotalSal + subTotalTom;
    taxesFinal = taxesPatty + taxesSal + taxesTom;
    totalFinal = subTotalFinal + taxesFinal;

    //displaying data
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallPrice, shirtNumPatty, subTotalPatty/(double)100.0, taxesPatty / (double)100.0, totalPatty / (double)100.0);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize,mediumPrice, shirtNumSal, subTotalSal / (double)100.0, taxesSal / (double)100.0, totalSal / (double)100.0);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largePrice, shirtNumTom, subTotalTom / (double)100.0, taxesTom / (double)100.0, totalTom / (double)100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotalFinal / (double)100.0, taxesFinal / (double)100.0, totalFinal / (double)100.0);

    //next section calculation excluding tax
    int toonies = subTotalFinal / 200;
    int tooniesAmount = subTotalFinal % 200;
    int loonies = tooniesAmount / 100;
    int looniesAmount = tooniesAmount % 100;
    int quarters = looniesAmount / 25;
    int quartersAmount = looniesAmount % 25;
    int dimes = quartersAmount / 10;
    int dimesAmount = quartersAmount % 10;
    int nickles = dimesAmount / 5;
    int nicklesAmount = dimesAmount % 5;
    int pennies = nicklesAmount / 1;
    int penniesAmount = nicklesAmount % 1;
    int totalShirts = shirtNumPatty + shirtNumSal + shirtNumTom;
    double averageCost1 = ((double)subTotalFinal / totalShirts) + 0.00005; // have to round off 



    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    //First Table
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subTotalFinal / (double)100.0);

    printf("Toonies  %3d %9.4lf\n", toonies, tooniesAmount / 100.0);
    printf("Loonies  %3d %9.4lf\n", loonies, looniesAmount / 100.0);
    printf("Quarters %3d %9.4lf\n", quarters, quartersAmount / 100.0);
    printf("Dimes    %3d %9.4lf\n", dimes, dimesAmount / 100.0);
    printf("Nickels  %3d %9.4lf\n", nickles, nicklesAmount / 100.0);
    printf("Pennies  %3d %9.4lf\n\n", pennies, penniesAmount / 100.0);
    printf("Average cost/shirt: $%.4lf\n\n", averageCost1 / 100);

    // Second Section Calculation With Tax
    toonies = totalFinal / 200;
    tooniesAmount = totalFinal % 200;
    loonies = tooniesAmount / 100;
    looniesAmount = tooniesAmount % 100;
    quarters = looniesAmount / 25;
    quartersAmount = looniesAmount % 25;
    dimes = quartersAmount / 10;
    dimesAmount = quartersAmount % 10;
    nickles = dimesAmount / 5;
    nicklesAmount = dimesAmount % 5;
    pennies = nicklesAmount / 1;
    penniesAmount = nicklesAmount % 1;
    double averageCost2 = ((double)totalFinal / totalShirts) + 0.00005;

    // Second Table
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", totalFinal / (double)100.0);

    printf("Toonies  %3d %9.4lf\n", toonies, tooniesAmount / 100.0);
    printf("Loonies  %3d %9.4lf\n", loonies, looniesAmount / 100.0);
    printf("Quarters %3d %9.4lf\n", quarters, quartersAmount / 100.0);
    printf("Dimes    %3d %9.4lf\n", dimes, dimesAmount / 100.0);
    printf("Nickels  %3d %9.4lf\n", nickles, nicklesAmount / 100.0);
    printf("Pennies  %3d %9.4lf\n\n", pennies, penniesAmount / 100.0);
    printf("Average cost/shirt: $%.4lf\n", averageCost2 / 100);


    return 0;
}