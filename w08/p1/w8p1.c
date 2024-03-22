/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


int getIntPositive(int* val) {
	int userInput;
	do
	{
		scanf("%d", &userInput);
		if (userInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			if (val != NULL)
			{
				*val = userInput;
			}
		}
	} while (userInput <= 0);
	return userInput;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* val) {
	double userInput;
	do
	{
		scanf("%lf", &userInput);
		if (userInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else {
			if (val != NULL)
			{
				*val = userInput;
			}
			
		}
	} while (userInput <= 0);
	return userInput;
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int numProduct) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numProduct);
	printf("NOTE: A 'serving' is %dg\n", GRAMS);
}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int userProductNum) {
	struct CatFoodInfo data;
	printf("\nCat Food Product #%d\n", userProductNum);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&data.sku);
	printf("PRICE         : $");
	getDoublePositive(&data.productPrice);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&data.productWeight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&data.calories);
	return data;
	}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(int sku, int calories, double price, double weight) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, price, weight, calories);
}

// 7. Logic entry point

void start(void) {
	struct CatFoodInfo array[MAXIMUM_PRODUCT_NUM] = { {0} };
	openingMessage(MAXIMUM_PRODUCT_NUM);

	int i;
	for ( i = 0; i < MAXIMUM_PRODUCT_NUM; i++)
	{
		array[i] = getCatFoodInfo(i + 1);
	}

	displayCatFoodHeader();
	for ( i = 0; i < MAXIMUM_PRODUCT_NUM; i++)
	{
		displayCatFoodData(array[i].sku, array[i].calories, array[i].productPrice, array[i].productWeight);
	}
}