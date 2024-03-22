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


// ----------------------------------------------------------------------------
// defines/macros
#define MAXIMUM_PRODUCT_NUM 3
#define GRAMS 64
#define CONVERSION_FACTOR_LBS_METRIC 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku, calories;
    double productPrice, productWeight;
};

struct ReportData
{
    int productsku, caloriesServing, weightGrams;
    double productPrice, weightLbs, weightKg, totalServings, costServing, costCalories;
};


// ----------------------------------------------------------------------------
// function prototypes
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* val);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* val);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProduct);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int userProductNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double *price, int calories, double *weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* ptrlbs, double* ptrKGResult);

// 9. convert lbs: g
int convertLbsG(const double* ptrlbs, int* ptrGResult);


// 10. convert lbs: kg / g
void convertLbs(const double* ptrlbs, double* ptrKGResult, int* ptrGResult);


// 11. calculate: servings based on gPerServ
double calculateServings(const int servingGram, const int totalGrams, double* ptrNumOfServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* ptrProductPrice, const double* ptrTotalServings, double* ptrCostPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* ptrProductPrice, const double* ptrTotalCalories, double* ptrCostPerCalorie);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo data);


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapestProduct);


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
