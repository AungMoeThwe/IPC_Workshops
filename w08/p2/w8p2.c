/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
	printf("\nCat Food Product #%d\n", userProductNum + 1);
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
void displayCatFoodData(int sku, double* price, int calories, double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* ptrlbs, double* ptrKGResult)
{
	double lbsTOkg = (*ptrlbs) / CONVERSION_FACTOR_LBS_METRIC;
	if (ptrKGResult != NULL)
	{
		*ptrKGResult = lbsTOkg;
	}
	return lbsTOkg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* ptrlbs, int* ptrGResult) 
{
	int lbsTOg = (int)(((*ptrlbs) / CONVERSION_FACTOR_LBS_METRIC) * 1000);
	if (ptrGResult != NULL)
	{
		*ptrGResult = lbsTOg;
	}
	return lbsTOg;
}

// 10. convert lbs: kg and g
void convertLbs(const double* ptrlbs, double* ptrKGResult, int* ptrGResult) 
{
	double lbsTOkg = (*ptrlbs) / CONVERSION_FACTOR_LBS_METRIC;
	int lbsTOg = (int)(((*ptrlbs) / CONVERSION_FACTOR_LBS_METRIC) * 1000);

	if (ptrKGResult != NULL && ptrGResult != NULL)
	{
		*ptrKGResult = lbsTOkg;
		*ptrGResult = lbsTOg;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingGram, const int totalGrams, double* ptrNumOfServings) 
{
	double servings = (double)totalGrams / servingGram;
	if (ptrNumOfServings != NULL)
	{
		*ptrNumOfServings = servings;
	}
	return servings;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double* ptrProductPrice, const double* ptrTotalServings, double* ptrCostPerServing)
{
	double costPerServing = (*ptrProductPrice) / (*ptrTotalServings);
	if (ptrCostPerServing != NULL)
	{
		*ptrCostPerServing = costPerServing;
	}
	return costPerServing;
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* ptrProductPrice,const double* ptrTotalCalories, double* ptrCostPerCalorie)
{
	double costPerCalorie = (*ptrProductPrice) / (*ptrTotalCalories);
	if (ptrCostPerCalorie != NULL) 
	{
		*ptrCostPerCalorie = costPerCalorie;
	}
	return costPerCalorie;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo data)
{
	struct ReportData report;

	// Normal entry
	report.productsku = data.sku;
	report.productPrice = data.productPrice;
	report.weightLbs = data.productWeight;
	report.caloriesServing = data.calories;
	// Calculating records 
	report.weightKg = convertLbsKg(&report.weightLbs, &report.weightKg);
	report.weightGrams = convertLbsG(&report.weightLbs, &report.weightGrams);
	report.totalServings = calculateServings(GRAMS, report.weightGrams, &report.totalServings);
	
	report.costServing = calculateCostPerServing(&report.productPrice, &report.totalServings, &report.costServing);
	// Calculating calories for calculating the cost per calories
	double totalCalories = report.caloriesServing * report.totalServings;
	report.costCalories = calculateCostPerCal(&report.productPrice, &totalCalories, &report.costCalories);

	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapestProduct)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.productsku, report.productPrice, report.weightLbs, report.weightKg, report.weightGrams, report.caloriesServing, report.totalServings, report.costServing, report.costCalories);
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo data)
{
	printf("Final Analysis\n");
	printf("--------------\n");

	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n\n", data.sku, data.productPrice);

	printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	// Creating Arrays
	struct ReportData report[MAXIMUM_PRODUCT_NUM] = { {0} };
	struct CatFoodInfo data[MAXIMUM_PRODUCT_NUM] = { {0} };

	int i, cheapest = 0;

	openingMessage(MAXIMUM_PRODUCT_NUM); //Intro

	for ( i = 0; i < MAXIMUM_PRODUCT_NUM; i++)
	{
		data[i] = getCatFoodInfo(i);
		report[i] = calculateReportData(data[i]);
	} //makes a detailes report of the cat food inputted and puts it into the report array

	displayCatFoodHeader();

	for ( i = 0; i < MAXIMUM_PRODUCT_NUM; i++)
	{
		displayCatFoodData(data[i].sku, &data[i].productPrice, data[i].calories, &data[i].productWeight);
	} // iteration to display each dataset into a chart

	double cheapProduct = report[0].costServing;
	for ( i = 0; i < MAXIMUM_PRODUCT_NUM; i++)
	{
		if (report[i].costServing <= cheapProduct)
		{
			cheapProduct = report[i].costServing;
			cheapest = i;
		} //checks through the array to take in the smallest cost/serving food. if found, marks the index of the cheapest.
	}

	printf("\n");

	displayReportHeader();

	for (i = 0; i < MAXIMUM_PRODUCT_NUM; i++)
	{
		displayReportData(report[i], cheapest);

		if (cheapest == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	for (i = 0; i < MAXIMUM_PRODUCT_NUM; i++)
	{
		if (i == cheapest)
		{
			displayFinalAnalysis(data[i]);
		}
	}// loops through the array and if the index is the same as the cheapest, it will display the sku and price, using the function


}
