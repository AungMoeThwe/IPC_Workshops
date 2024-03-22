/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P1)
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
#define MAXITEM 10
int main(void)
{
	const double max = 400000.00, min = 500.00;
	const double minCost = 100.00;
	double netIncome, totalCost = 0;
	int item = 3, i;
	double cost[MAXITEM];
	int priority[MAXITEM];
	char finance[MAXITEM];
	

	printf("+--------------------------+\n+   Wish List Forecaster   |\n+--------------------------+\n");

	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &netIncome);
		if (netIncome < min)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		}
		if (netIncome > max)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}
	} while ((netIncome > max) || (netIncome <= min)); //validating loop for money

	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &item);
		if (item > MAXITEM || item < 1)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}

	} while (item > MAXITEM || item < 1);//validating loop for num of items

	

	for ( i = 0; i < item; i++) // iteration depending on the number of items.
	{
		int costValid = 0, priorityValid = 0, financeValid = 0; //setting flags for each parralel array
		printf("\nItem-%d Details:\n", i + 1);

		while (!costValid)  // cost manipulation
		{
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);
			if (cost[i] >= minCost)
			{
				totalCost += cost[i];
				costValid = 1;
			}
			else
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		}

		while (!priorityValid)  //priority manipulation
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);
			if (priority[i] > 0 && priority[i] < 4)
			{
				priorityValid = 1;
			}
			else
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		}

		while (!financeValid) // finance manipulation
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i]);
			if (finance[i] == 'y' || finance[i] == 'n')
			{
				financeValid = 1;
			}
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		}
	}

	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for ( i = 0; i < item; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);

	printf("Best of luck in all your future endeavours!\n\n");
	
	return 0;
}

/*
	HELPER: printf formatting statements....
	=========================================

	Step #7:
		printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");

		printf("%3d  %5d    %5c    %11.2lf\n", ...


	Step #8:
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", ...

*/