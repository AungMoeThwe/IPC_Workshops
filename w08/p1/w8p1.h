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


#define MAXIMUM_PRODUCT_NUM 3
#define GRAMS 64


// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku, calories;
    double productPrice, productWeight;
};




// ----------------------------------------------------------------------------
// function prototypes
// 1. Get user input of int type and validate for a positive non-zero number

int getIntPositive(int* val);


//    (return the number while also assigning it to the pointer argument)


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

void displayCatFoodData(int sku, int calories, double price, double weight);

// 7. Logic entry point

void start(void);
