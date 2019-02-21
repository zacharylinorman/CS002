/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Noise Signals
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/30/19
 ****************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
/****************************************************************
 * Noise Signals
 * ______________________________________________________________
 * This program is separated into four parts. The first part
 * calculates the mean and variance of two randomly-
 * generated sequences of floats ranging from 4 to 10. The two
 * sequences are of size 100 and 10000. The second part does the
 * same but with two arrays of size 500 and hand-calculated
 * bounds of given specifications. The third part does the same
 * as the second, but with different hand-calculated bounds. The
 * fourth part uses a different function to find the bounds given
 * a mean and variance.
 * ______________________________________________________________
 * INPUT:
 * OUTPUT:
 *      Part 1-3: Outputs the practical and theoretical means and
 *                variances of the sequences.
 *      Part 4  : Outputs the bounds calculated by the function
 *
 ****************************************************************/


// PROTOTYPES
/****************************************************************
 * randFloat(double, double)
 *  This function returns a random float between a and b
 ****************************************************************/
double randFloat(double a,      // Lower Bound
                 double b);     // Upper Bound

/****************************************************************
 * rand_mv(double, double)
 *  This function returns a random float between two bounds found
 *  using the mean and variance variables.
 ****************************************************************/
double rand_mv(double mean,     // Given mean of sequence
               double variance);// Given variance of the sequence

/****************************************************************
 * generateSequenceAndFindMeanAndVariance()
 *  This function generates a random sequence of values bounded
 *  by a and b of size size. It then finds the mean and variance
 *  of the sequence and returns the values through reference
 *  variables.
 ****************************************************************/
void generateSequenceAndFindMeanAndVariance(int size,         // Array size
                                            double a,         // L-Bound
                                            double b,         // U-Bound
                                            double& mean,     // M-Return
                                            double& variance);// V-Return

int main()
{
    srand(500); // Set Seed
    // **Each part separated by its own block for portability** //
    // PART 1
    {
        // VARIABLES
        double a = 4, b = 10; // Constants -> the bounds

        double mean,          // Practical mean
               variance;      // Practical variance

        /* PROCESSING & OUTPUT - Generate the sequences and calculate
         *                       values using the function
         *                       generateSequenceAndFindMeanAndVariance
         *                       Output theoretical and practical means and
         *                       variances
         */
        // Size 100
        generateSequenceAndFindMeanAndVariance(100, a, b, mean, variance);
        cout << (a + b) / 2 << " " << mean << " "
             << pow(b - a, 2)/12 << " " << variance << endl;

        // Size 10000
        generateSequenceAndFindMeanAndVariance(10000, a, b, mean,
                                               variance);
        cout << (a + b) / 2 << " " << mean << " "
             << pow(b - a, 2)/12 << " " << variance << endl;

    }
    cout << endl;
    // PART 2
    {
        // VARIABLES
        // Bounds
        double a = 8 - (sqrt(6)+8)/ 2,
               b = (sqrt(6) + 8) / 2; // 0.5 variance
        double c = 4 - sqrt(6),
               d = 4 + sqrt(6);
        double mean,          // Practical mean
               variance;      // Practical variance

        /* PROCESSING & OUTPUT - Generate the sequences and calculate
         *                       values using the function
         *                       generateSequenceAndFindMeanAndVariance
         *                       Output theoretical and practical means and
         *                       variances
         */
        // Variance 0.5
        generateSequenceAndFindMeanAndVariance(500, a, b, mean, variance);
        cout << (a + b) / 2 << " " << mean << " "
             << pow(b - a, 2)/12 << " " << variance << endl;

        // Variance 2
        generateSequenceAndFindMeanAndVariance(500, c, d, mean,
                                               variance);
        cout << (c + d) / 2 << " " << mean << " "
             << pow(c - d, 2)/12 << " " << variance << endl;

    }
    cout << endl;
    // PART 3
    {
        double a = -3,
               b = 3; // 0 mean
        double c = -7,
               d = -1;

        double mean,          // Practical mean
               variance;      // Practical variance

        /* PROCESSING & OUTPUT - Generate the sequences and calculate
         *                       values using the function
         *                       generateSequenceAndFindMeanAndVariance
         *                       Output theoretical and practical means and
         *                       variances
         */
        // Mean 0
        generateSequenceAndFindMeanAndVariance(500, a, b, mean, variance);
        cout << (a + b) / 2 << " " << mean << " "
             << pow(b - a, 2)/12 << " " << variance << endl;

        // Mean -4
        generateSequenceAndFindMeanAndVariance(500, c, d, mean,
                                               variance);
        cout << (c + d) / 2 << " " << mean << " "
             << pow(c - d, 2)/12 << " " << variance << endl;
    }

    cout << endl;
    // PART 4
    {
        double mean, variance;
        cout << "Enter Mean: ";
        cin >> mean;
        cout << endl;

        cout << "Enter Variance: ";
        cin >> variance;
        cout << endl;

        cout << rand_mv(mean, variance) << endl;

    }
    return 0;
}

/*This function generates a random double value between a and b*/
double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

double rand_mv(double mean, double variance){
    // VARIABLES
    double a,   // Lower bound
           b;   // Upper bound
    // PROCESSING - Use mean and variance to calculate bounds
    a = mean - sqrt(3 * variance); // Formula to find a
    b = mean + sqrt(3 * variance); // Formula to find b

    // OUTPUT - output the bounds and return a random value between them
    cout << a << " " << b << endl;
    return (randFloat(a, b));
}
void generateSequenceAndFindMeanAndVariance(int size, double a, double b,
                                    double& mean, double& variance){
    // VARIABLES
    double arr[size];   // The array of size size
    double sum;         // Sum placeholder

    // INITIALIZATION
    sum = 0;            // Initialize sum to 0

    // PROCESSING - generate random sequence between a and b
    for(int i = 0; i < size; i++){
        arr[i] = randFloat(a, b);
        sum += arr[i];  // Add generated number to sum
    }
    mean = sum/size;    // Calculate mean and return it by reference


    sum = 0;    // Reset sum to use for calculating variance
    for(int i = 0; i < size; i++){
        sum += pow(arr[i] - mean, 2); // Find variance numerator
    }
    variance = sum/size; // Calculate variance and return by reference
}
