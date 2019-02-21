/****************************************************************
 * AUTHOR        : Zachary Norman & Kevin Ngo
 * ASSIGNMENT    : Lab 08
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/23/19
 ****************************************************************/
#include <iostream>

using namespace std;

/****************************************************************
 * Lab 08
 * ______________________________________________________________
 * This program contains two exercises. The first continues to
 * sum the digits of user inputted numbers and outputs until the
 * user wants to stop. The second prints a table of all prime
 * numbers between user inputted bounds;
 * ______________________________________________________________
 * FUNCTIONS:
 *      int sumDigits(int)  : This function returns the sum of
 *                            the digits of the given integer
 *
 *      int isPrime(int)    : This function returns a boolean
 *                            value indicating whether the given
 *                            integer is prime
 * INPUT:
 *      ex          : The exercise number
 *
 *      num         : The number to sum the digits of
 *
 *      lowerBound  : The lower bound of numbers to check for
 *                    primes
 *      upperBound  : The upper bound of numbers to check for
 *                    primes
 *
 * OUTPUT:
 *      ex1         : The sum of the digits of user inputted nums
 *      ex2         : A table of prime numbers between bounds
 *
 *
 ****************************************************************/


// PROTOTYPES
/****************************************************************
 * sumDigits(int)
 *  This function returns the sum of the digits of the given
 *  integer
 ****************************************************************/
int sumDigits(int num); // The number to sum the digits of

/****************************************************************
 * isPrime(int)
 *  This function returns a boolean value indicating whether the
 *  given integer is prime
 ****************************************************************/
bool isPrime(int num); // The number to check if prime

int main()
{
    // INPUT - receive exercsie number
    int ex; // The exercise number
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    if(ex == 1)
    {
        // EXERCISE 1 CODE

        //VARIABLES
        int num; // The number to sum the digits of

        do
        {
            // INPUT receive the number to sum the digits of
            cout << "Please enter an integer (0 to quit): ";
            cin >> num;
            cout << endl;

            if(num != 0) // User does not want to stop
            {
                // OUTPUT - Use sumDigits(int) to find sum of digits
                cout << "The sum of the digits of " << num << " is "
                     << sumDigits(num) << endl;
            }else // User wants to stop
            {
                // OUTPUT - bye bye message :(
                cout << "Goodbye " << endl;
            }
        }while(num != 0); // Continue as long as user does not enter 0


    } else if(ex == 2)
    {
        // EXERCISE 2 CODE

        // VARIABLES
        int lowerBound, upperBound;

        // INPUT - receive the lower and upper bounds
        cout << "Please input two positive numbers: ";
        cin >> lowerBound >> upperBound;
        cout << endl;

        // OUTPUT - Output a table of prime numbers between bounds
        cout << "The prime numbers between " << lowerBound << " and "
             << upperBound << " are: " << endl;

        // PROCESSING - loop through all numbers between bounds
        for(int i = lowerBound, k = 0; i < upperBound; i++)
        { // k to check when to move to next line
            if(isPrime(i)) // use isPrime(int) to check if i is prime
            {
                k++; // Increment k

                cout << i << "\t";

                if(k % 8 == 0) // If there have been 8 printed, next line
                {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }


    return 0;
}

// FUNCTION DEFINITIONS

/****************************************************************
 * sumDigits(int)
 *  This function returns the sum of the digits of the given
 *  integer
 ****************************************************************/
int sumDigits(int num) // The number to sum the digits of
{
    // RETURN VARIABLE
    int sum = 0; // The sum of digits

    // PROCESSING - summing the digits
    if(num < 0) // If given negative number, make it positive
    {
        num *= -1;
    }

    while(num != 0) // Continue through all digits
    {
        sum += num % 10; // Add last digit
        num /= 10; // Take off last digit from number
    }
    return sum;
}

/****************************************************************
 * isPrime(int)
 *  This function returns a boolean value indicating whether the
 *  given integer is prime
 ****************************************************************/
bool isPrime(int num) // The number to check if prime
{
    // RETURN VARIABLE
    bool prime = true; // Whether the number is prime or not
                       // Assume it is until proven wrong

    // PROCESSING - checking if number is prime
    for(int i = 2; i <= num/2; i++) // Loop from 2 to the number / 2
    {
        if(num % i == 0) // If the number is divisible, then not prime
        {
            prime = false;
            break; // Don't need to check anymore
        }
    }
    return prime;
}
