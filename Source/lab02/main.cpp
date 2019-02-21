/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Lab 02
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/9/19
 ****************************************************************/

#include <iostream>

using namespace std;

/****************************************************************
 * LAB 02
 * ______________________________________________________________
 * This program either calculates an ISBN checksum, or determines
 * the position of a character depending on user input.
 * ______________________________________________________________
 * INPUT:
 *      ex          : The exercise number -> input from user
 *      isbn        : The ISBN number -> input from user
 *      character   : The character -> input from user
 *
 * OUTPUT:
 *      If the user enters 1 for ex:
 *          checksum: The checksum of the user-inputted ISBN
 *      If the user enters 2 for ex:
 *          Outputs the position of user-inputted character
 ****************************************************************/
int main()
{
    // Variables
    int ex;     // INPUT - The exercise number

    cout << "************************************************************"
            "****" << endl;
    cout << "  AUTHOR        : Zachary Norman" << endl;
    cout << "  ASSIGNMENT    : Lab 02" << endl;
    cout << "  CLASS         : CS02" << endl;
    cout << "  SECTION       : MTWH: 7:30-12:30" << endl;
    cout << "  DUE DATE      : 1/9/19" << endl;
    cout << "************************************************************"
            "****" << endl;


    // INPUT - Receiving the exercise number from user
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    // PROCESSING - if-block running either exercise 1 or 2 based on ex
    if ( ex == 1 )
    {

        // All Exercise 1 code

        // Variables
        int isbn;       // INPUT - The ISBN number
        int checksum;   // OUTPUT - The checksum of the user-inputted ISBN

        // INPUT - Receiving the ISBN number from user
        cout << "Please enter the first 9 digits of the ISBN: ";
        cin >> isbn;
        cout << endl;

        // PROCESSING - Calculating the checksum from the ISBN
        checksum = 0;
        for(int i = 9; i > 0; i--){
            checksum += isbn%10 * i;
            isbn /= 10;
        }
        checksum %= 11;

        // OUTPUT - Printing out the checksum value
        cout << "Checksum: " << checksum << endl;
    }
    else if ( ex == 2 )
    {
        // All Exercise 2 code

        // Variables
        char character; // INPUT - The character

        // INPUT - Receiving the character from user
        cout << "Enter a character: ";
        cin >> character;
        cout << endl;

        /* OUTPUT & PROCESSING - Calculating the character's position and
         *                       printing it.
         */
        cout << character << " is letter " << character - 'a' + 1 << endl;
    }

    return 0;
}
