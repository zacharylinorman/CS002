/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Lab 06
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/17/19
 ****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/****************************************************************
 * Lab 06
 * ______________________________________________________________
 * This program reads from an input file and writes to an output
 * file
 * ______________________________________________________________
 * INPUT:
 *      inFile      : The file input stream to use to read file
 *                    Contains a length, width, radius, first
 *                    name, last name, age, balance, interest
 *                    rate, and a letter.
 * OUTPUT:
 *      outFile     : The file output stream to use to write file
 *                    Contains properties of a rectangle,
 *                    information about a person and their
 *                    initial balance, as well as what the
 *                    balance becomes after a month, and the
 *                    ASCII character that comes after the input
 *                    character
 *
 ****************************************************************/

int main()
{
    // VARIALBES
    ifstream inFile;  // INPUT - the file input stream
    ofstream outFile; // OUTPUT - the file output stream

    // INPUT VARIABLES - The variables to store the input stream data
    double length, width, radius; // Rectangle properties
    string firstName, lastName; // Person name
    int age; // Person age
    double balance, interestRate; // Person bank info
    char letter; // Character

    // INPUT & PROCESSING - Open file and extract data
    inFile.open("inData.txt"); // Attempt to open input file
    if(inFile){ // Check to see if file exists
        // PROCESSING - extract file data and place into variables
        inFile >> length >> width >> radius >> firstName >> lastName
              >> age >> balance >> interestRate >> letter;
        inFile.close(); // Close the input stream
    }else{ // FILE DOES NOT EXIST
        cout << "Error: File not found." << endl;
    }
    // OUTPUT - Output data to console for Hypercode
    cout << fixed << setprecision(2); // Set the floating point precision
    cout << "Rectangle:" << endl << "Length = " << length << ", width = "
         << width << ", area = " << (length * width) << ", perimeter = "
         << 2 * (length + width) << endl << endl

         << "Circle:" << endl << "Radius = " << radius << ", area = "
         << (3.14159 * radius * radius) << ", circumference = "
         << (2 * 3.14159 * radius) << endl << endl

         << "Name: " << firstName << " " << lastName << ", age: " << age
         << endl << "Beginning balance = $" << balance
         << ", interest rate = " << interestRate << endl
         << "Balance at the end of the month = $"
         << balance * (1 + ((interestRate / 100) / 12)) << endl << endl

         << "The character that comes after " << letter
         << " in the ASCII set is " << static_cast<char>(letter+1) << endl;

    // OUTPUT - Open or create the file, set precision, then output data
    outFile.open("outData.txt");
    outFile << fixed << setprecision(2);
    outFile << "Rectangle:" << endl << "Length = " << length
            << ", width = " << width << ", area = " << (length * width)
            << ", perimeter = " << 2 * (length + width) << endl << endl

            << "Circle:" << endl << "Radius = " << radius << ", area = "
            << (3.14159 * radius * radius) << ", circumference = "
            << (2 * 3.14159 * radius) << endl << endl

            << "Name: " << firstName << " " << lastName << ", age: "
            << age << endl << "Beginning balance = $" << balance
            << ", interest rate = " << interestRate << endl
            << "Balance at the end of the month = $"
            << balance * (1 + ((interestRate / 100) / 12)) << endl << endl

            << "The character that comes after "
            << letter << " in the ASCII set is "
            << static_cast<char>(letter+1) << endl;
    outFile.close(); // Close the output stream

    return 0;
}
