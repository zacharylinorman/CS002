/****************************************************************
 * AUTHOR        : Zachary Norman & Shilong Zhang
 * ASSIGNMENT    : Lab 10
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/28/19
 ****************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
/****************************************************************
 * Lab 10
 * ______________________________________________________________
 * This program calculates the mean and variance of two randomly-
 * generated sequences of floats ranging from 4 to 10. The two
 * sequences are of size 100 and 10000.
 * ______________________________________________________________
 * INPUT:
 * OUTPUT:
 *      The first line outputs the theoretical mean and variance
 *      of the sequence with 100 terms. The second line outputs
 *      the same of the sequence with 10000 terms.
 *
 ****************************************************************/


// PROTOTYPES
/****************************************************************
 * randFloat(double, double)
 *  This function returns a random float between a and b
 ****************************************************************/
double randFloat(double a, double b);

int main()
{
    // VARIABLES

    double a = 4, b = 10; // Constants -> the range of generated doubles

    double arr1[100];   // The first array
    double arr2[10000]; // The second array


    double sum;        // Sum placeholder

    double mean1;       // Practical mean of array 1
    double variance1;   // Practical variance of array 1

    double mean2;       // Practical mean of array 2
    double variance2;   // Practical variance of array 2


    // PROCESSING - Generate the sequences and calculate values
    srand(500); // Set Seed

    // ARRAY 1 - size 100
    sum = mean1 = variance1 = 0; // Initialize variables
    // Fill sequence with random numbers doubles between 4 and 10
    for(int i = 0; i < 100; i++){
        arr1[i] = randFloat(a, b);
        sum += arr1[i]; // Add to the sum to calculate mean at end
    }
    mean1 = sum/100;    // Calculate practical mean

    sum = 0;            // Reset sum variable to use to find variance
    for(int i = 0; i < 100; i++){ // Find numerator of variance formula
        sum += pow(arr1[i] - mean1, 2);
    }
    variance1 = sum/(100); // Calculate practical variance

    // ARRAY 2 - size 10000
    sum = mean2 = variance2 = 0;  // Initialize variables && reset sum
    // Fill sequence with random numbers doubles between 4 and 10
    for(int i = 0; i < 10000; i++){
        arr2[i] = randFloat(a, b);
        sum += arr2[i]; // Add to the sum to calculate mean at end
    }
    mean2 = sum/10000;  // Calculate practical mean

    sum = 0;            // Reset sum variable to use to find variance
    for(int i = 0; i < 10000; i++){// Find numerator of variance formula
        sum += pow(arr2[i] - mean2, 2);
    }
    variance2 = sum/(10000);// Calculate practical variance

    // OUTPUT - output theoretical and practical means and variances
    // ARRAY 1 - size 100
    cout << (a + b) / 2 << " " << mean1 << " "
         << pow(b - a, 2)/12 << " " << variance1 << endl;
    // ARRAY 2 - size 10000
    cout << (a + b) / 2 << " " << mean2 <<  " "
         << pow(b - a, 2)/12 << " " << variance2 << endl;


    return 0;
}

/*This function generates a random double value between a and b*/
double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

