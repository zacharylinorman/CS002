/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Lab 13
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 2/1/19
 ****************************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
/****************************************************************
 * Temperature Distribution Grid
 * ______________________________________________________________
 * This program receives an input file from the user to setup a
 * temperature distribution grid. The inner cells are then
 * calculated, and outputted to the console and a specified
 * output file.
 * ______________________________________________________________
 * INPUT:
 *      inFileName      : The name of the input file
 *      outFileName     : The name of the output file
 * OUTPUT:
 *      The inner cells of the temperature distribution grid to
 *      the console and the output file.
 ****************************************************************/

//GLOBAL VARIABLES
const int ROWS = 6,     // Number of rows in distribution grid
          COLUMNS = 8;  // Number of columns in distribution grid

int main()
{
    // VARIABLES
    double grid[ROWS][COLUMNS];     // The temperature distribution grid
    string inFileName,              // Input file name
           outFileName;             // Output file name
    double top,                     // Top of temp gird
           left,                    // Left of temp grid
           right,                   // Right of temp grid
           bottom;                  // Bottom of temp grid
    double tolerance;               // The tolerance of the difference
                                    // in inner cells
    ifstream inputStream;           // The input stream
    ofstream outputStream;          // The output stream
    double difference;              // The max difference of iteration
    double val;                     // The temporary value of iteration

    // INPUT - Receive input and output file names
    cout << "Enter input file name: ";
    cin >> inFileName;
    cout << endl << endl;

    cout << "Enter output file name: ";
    cin >> outFileName;
    cout << endl << endl;

    // PROCESSING - open input stream and receive the initial grid
    inputStream.open(inFileName.c_str()); // Open input file
    if(inputStream){
        // Extract variables
        inputStream >> top >> right >> bottom >> left >> tolerance;
    }else{
        cout << "Cannot open file" << endl;
    }
    inputStream.close(); // Close the filestream

    // Setup the top and bottom of the grid
    for(int i = 0; i < COLUMNS; i++){
        grid[0][i] = top;
        grid[ROWS-1][i] = bottom;
    }

    // Setup the left and right of the grid
    for(int i = 1; i < ROWS-1; i++){
        grid[i][0] = left;
        grid[i][COLUMNS-1] = right;
    }

    // Initialize the inner cells of the matrix to 0
    for(int i = 1; i < ROWS-1; i++){
        for(int k = 1; k < COLUMNS-1; k++){
            grid[i][k] = 0;
        }
    }

    // PROCESSING - calculate inner cells
    do{
        difference = 0; // Reset max difference each iteration
        for(int i = 1; i < ROWS-1; i++){ // Go through the inner cells
            for(int k = 1; k < COLUMNS-1; k++){
                val = (grid[i-1][k] +   // Find the average
                       grid[i+1][k] +
                       grid[i][k-1] +
                       grid[i][k+1])
                       / 4;
                // If the difference is greater than the previous diff.
                if(fabs(val - grid[i][k]) > difference){
                    // Set the new greatest difference
                    difference = fabs(val - grid[i][k]);
                }
                // Set the inner cell to its new value
                grid[i][k] = val;

            }
        }
        // Continue as long as the greatest difference is > tolerance
    } while(difference > tolerance);

    // OUTPUT - output inner cells to file and console
    outputStream.open(outFileName.c_str()); // Open/Create output file
    if(outputStream){
        // Loop through inner cells to output
        for(int i = 1; i < ROWS-1; i++){
            for(int k = 1; k < COLUMNS-1; k++){
                outputStream << grid[i][k] << " ";
                cout << grid[i][k] << " ";
            }
            outputStream << endl;
            cout << endl;
        }
    } else{
        cout << "Unable to create file!" << endl;
    }
    outputStream.close(); // Close the filestream

    return 0;
}
