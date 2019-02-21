/****************************************************************
 * AUTHOR        : Zachary Norman & Kevin Ngo
 * ASSIGNMENT    : Lab 09
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/24/19
 ****************************************************************/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/****************************************************************
 * Lab 06
 * ______________________________________________________________
 * This program contains two exercises. The first reads from a
 * given file and returns the largest, smallest, and average
 * values. The second reads from a user-inputted file and returns
 * the largest, smallest, and average values.
 * ______________________________________________________________
 * INPUT:
 *      ex          : The exercise number
 *      filepath    : For exercise 2: the path of the file
 * OUTPUT:
 *      The largest, smallest, and average value in the read file
 *
 ****************************************************************/

// PROTOTYPES:

/****************************************************************
 * readNumbers(string, int&, int&, double&)
 *  Accepts a filepath, the variable to accept the largest value,
 *  the variable to accept the smallest value, and the variable to
 *  accept the average value. It reads through the integers in
 *  the file to determine these values.
 ****************************************************************/
void readNumbers(string,    // The filepath
                 int&,      // The int to give large to
                 int&,      // The int to give small to
                 double&);  // The double to give average to

/****************************************************************
 * readFile(string, int&, int&, double&)
 *  Accepts a filepath, the variable to accept the largest value,
 *  the variable to accept the smallest value, and the variable to
 *  accept the average value. If the file is successfully opened,
 *  the function returns true- otherwise false. It reads through
 *  the integers in the file to determine these values.
 ****************************************************************/
bool readFile(string,   // The filepath
              int&,     // The int to give large to
              int&,     // The int to give small to
              double&); // The double to give average to

int main()
{
    // VARIABLES
    int ex;             // The exercise number
    int large,          // The variable to hold the largest number
        small;          // The variable to hold the smallest number
    double average;     // The variable to hold the average number
    string filepath;    // The variable to hold the file path

    // INPUT - Receive exercise number
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    // INITIALIZE VARIABLES
    // Large should be set to min integer, small to max integer
    large = small = average = 0;
    filepath = "numbers.dat"; // Default file path

    if(ex == 1)
    {
        // EXERCISE 1 CODE

        // Use readNumbers() to find values of default filepath
        readNumbers(filepath, large, small, average);

        // OUTPUT - output the min, max, and average values
        cout << "The min is: " << small << endl;
        cout << "The max is: " << large << endl;
        cout << "The average is: " << average << endl;

    }else if (ex == 2)
    {
        // EXERCISE 2 CODE

        // INPUT - Receive filepath from user
        cout << "Enter the name of the file: ";
        cin >> filepath;
        cout << endl;

        // If the file is successfully opened
        if(readFile(filepath, large, small, average))
        {
            // OUTPUT - output the min, max, and average
            cout << "The max number is: " << large << endl;
            cout << "The min number is: " << small << endl;
            cout << "The average is: " << average << endl;
        }else // File is not successfully opened
        {
            // OUTPUT - error message
            cout << "Cannot open the file!" << endl;
        }
    }

    return 0;
}

/****************************************************************
 * readNumbers(string, int&, int&, double&)
 *  Accepts a filepath, the variable to accept the largest value,
 *  the variable to accept the smallest value, and the variable to
 *  accept the average value. It reads through the integers in
 *  the file to determine these values.
 ****************************************************************/
void readNumbers(string filepath, int& large, int& small, double& average)
{
    // VARIABLES
    ifstream in;       // File Input stream

    int num;           // The current number
    double sum,        // The sum of numbers
           count;      // How many numbers

    // INITIALIZE VARIABLES
    sum = count = 0;

    // Attempt to open file
    in.open(filepath.c_str());

    // If successfully opened
    if(in)
    {
        // As long as the file still has values
        while(in >> num)
        {
            // If the value is greater than the current largest
            if(num > large)
            {
                // Set new largest value
                large = num;
            }else if(num < small)
            {// If the value is smaller than the current smallest

                // Set new smallest value
                small = num;
            }
            sum += num; // Add value to sum of all numbers
            count++;    // Increment count of all numbers
        }
        sum /= count;   // Calculate average value
        average = sum;  // Return the average

    }
    in.close(); // Close the input stream
}

/****************************************************************
 * readFile(string, int&, int&, double&)
 *  Accepts a filepath, the variable to accept the largest value,
 *  the variable to accept the smallest value, and the variable to
 *  accept the average value. If the file is successfully opened,
 *  the function returns true- otherwise false. It reads through
 *  the integers in the file to determine these values.
 ****************************************************************/
bool readFile(string filepath, int& large, int& small, double& average)
{
    // VARIABLES
    ifstream in;       // File Input stream

    int num;           // The current number
    double sum,        // The sum of numbers
           count;      // How many numbers

    // INITIALIZE VARIABLES
    sum = count = 0;

    // Attempt to open file
    in.open(filepath.c_str());

    // If successfully opened
    if(in)
    {
        // As long as the file still has values
        while(in >> num)
        {
            // If the value is greater than the current largest
            if(num > large)
            {
                // Set new largest value
                large = num;
            }else if(num < small)
            {// If the value is smaller than the current smallest

                // Set new smallest value
                small = num;
            }
            sum += num; // Add value to sum of all numbers
            count++;    // Increment count of all numbers
        }
        sum /= count;   // Calculate average value
        average = sum;  // Return the average
        return true;    // File was successfully opened - return true;
    }else{ // File was not successfully opened- return false
        return false;
    }
    in.close(); // Close the input stream

}
