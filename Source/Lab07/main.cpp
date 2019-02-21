/****************************************************************
 * AUTHOR        : Zachary Norman & Kevin Ngo
 * ASSIGNMENT    : Lab 07
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/22/19
 ****************************************************************/
#include <iostream>

using namespace std;

/****************************************************************
 * Lab 07
 * ______________________________________________________________
 * This program receives liters and miles from the user, and
 * outputs the gas mileage. It allows the user to continue doing
 * this until they want to stop. When they stop, it will take
 * 2 sets of liters and miles from the user, calculate the gas
 * mileages, and output which one is better.
 * ______________________________________________________________
 * FUNCTIONS:
 *      mpgCalculator(int, int) : This function takes two doubles,
 *                                one being liters and one miles
 *                                It returns the ratio of miles
 *                                per gallon.
 *
 * INPUT:
 *      liters      : Number of liters of gas consumed
 *      miles       : Number of miles traveled
 *      cont        : Whether to continue or not
 *
 *      liters1     : Number of liters of gas consumed for car 1
 *      miles1      : Number of miles traveled for car 1
 *      liters2     : Number of liters of gas consumed for car 2
 *      miles2      : Number of miles traveled for car 2
 *
 * OUTPUT:
 *      The gas mileage of the car until the user stops.
 *
 *      The gas mileage of the two cars, and which one is better
 *
 *
 ****************************************************************/

// GLOBAL VARIABLES
const double litersToGallons = 0.264179; // The ratio of liters to gallons

// PROTOTYPES
/****************************************************************
 * mpgCalculator
 *  This function takes two doubles, one being liters and one
 *  miles. It returns the ratio of miles per gallon.
 ****************************************************************/
double mpgCalculator(double liters,    // IN - number of liters
                     double miles);    // IN - number of miles

int main()
{
    // VARIABLES
    char cont;  // Whether to continue or not
    double liters, // Number of liters of gas consumed
           miles;  // NUmber of miles traveled

    // INPUT & PROCESSING - receives values and outputs mpg w/ function
    do
    {
        cout << "Enter the number of liters of gas consumed: ";
        cin >> liters;
        cout << endl;

        cout << "Enter the number of miles traveled: ";
        cin >> miles;
        cout << endl;

        // OUTPUT - Calculates mpg with function to output
        cout << "This car gets " << mpgCalculator(liters, miles)
             << " miles per gallon." << endl;

        cout << "Calculate again? ";
        cin >> cont;
        cout << endl;
    }while(cont == 'y'); // Loops until user says no

    cout << endl << endl;

    // VARIABLES
    double liters1, // Number of liters of gas consumed for car 1
           liters2, // Number of miles traveled for car 1
           miles1,  // Number of liters of gas consumed for car 2
           miles2;  // Number of miles traveled for car 2

    double mpg1, // MPG for first car
           mpg2; // MPG for second car

    // INPUT - receive the liters and miles for the two cars
    // Vals for first car
    cout << "Enter the number of liters consumed for the first car: ";
    cin >> liters1;
    cout << endl;

    cout << "Enter the number of miles traveled for the first car: ";
    cin >> miles1;
    cout << endl;

    // Vals for second car
    cout << "Enter the number of liters consumed for the second car: ";
    cin >> liters2;
    cout << endl;

    cout << "Enter the number of miles traveled for the second car: ";
    cin >> miles2;
    cout << endl;

    // PROCESSING - calculate the two mpgs
    mpg1 = mpgCalculator(liters1, miles1);
    mpg2 = mpgCalculator(liters2, miles2);

    cout << endl << endl;

    // OUTPUT - outputs the mpgs of the two cars
    cout << "The first car gets " << mpg1 << " miles per gallon." << endl;
    cout << "The second car gets " << mpg2 << " miles per gallon." << endl;

    // PROCESSING & OUTPUT - Checks to see which mpg is higher to output
    if(mpg1 > mpg2)
    {
        cout << "The first car has better gas mileage." << endl;
    }else if(mpg2 > mpg1)
    {
        cout << "The second car has better gas mileage." << endl;
    }else
    {
        cout << "The cars get equal gas mileage." << endl;
    }


    return 0;
}

// FUNCTION DEFINITIONS
double mpgCalculator(double liters, // IN - number of liters
                     double miles)  // IN - number of miles
{
    // PROCESSING VARIABLES
    double milesPerGallon, gallon;
    gallon = liters * litersToGallons; // Converts liters to gallons

    milesPerGallon = miles / gallon; // Calculates mpg

    return milesPerGallon; // Returns calculated mpg
}
