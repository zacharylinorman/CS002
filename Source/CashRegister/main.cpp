/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Cash Register
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/11/19
 ****************************************************************/

#include <iostream>

using namespace std;
/****************************************************************
 * Cash Register
 * ______________________________________________________________
 * This program accepts 2 inputs from the user- the purchase
 * amount, and amount received. It then calculates the change,
 * and displays the appropriate change in coins.
 * ______________________________________________________________
 * INPUT:
 *      purchaseAmount   : The amount to be paid -> input from
 *                                                  user
 *      receivedAmount   : The amount received -> input from user
 *
 * OUTPUT:
 *      change : the change in dollars
 *      The program outputs the change, as well as the what coins
 *      should be used.
 ****************************************************************/

int main()
{
    // Variables
    double purchaseAmount,      // INPUT - The amount to be paid
           receivedAmount;      // INPUT - The amount received
    double change;              // OUTPUT - The change in dollars
    int changeInPennies;        /* PROCESSING - Used to calculate change
                                 *              in coins
                                 */

    // INPUT

    purchaseAmount = 0;
    cout << "Enter purchase amount: ";
    cin >> purchaseAmount;
    cout << endl;

    receivedAmount = 0;
    cout << "Enter amount received: ";
    cin >> receivedAmount;
    cout << endl;

    // OUTPUT + PROCESSING

    change = receivedAmount - purchaseAmount; //Calculate change in dollars
    cout << "Total Change: $" << change << endl;
    cout << endl;

    //Calculate change in pennies
    changeInPennies = static_cast<int>(change * 100 + 0.5);


    //Apply algorithm
    cout << "dollars " << changeInPennies / 100 << endl;
    changeInPennies %= 100;

    cout << "quarters " << changeInPennies / 25 << endl;
    changeInPennies %= 25;

    cout << "dimes " << changeInPennies / 10 << endl;
    changeInPennies %= 10;

    cout << "nickels " << changeInPennies / 5 << endl;
    changeInPennies %= 5;

    cout << "pennies " << changeInPennies << endl;



    return 0;
}
