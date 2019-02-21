/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Math Specifications
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/9/19
 ****************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/****************************************************************
 * Math Specifications
 * ______________________________________________________________
 * This program does a math specification based on user input
 * ______________________________________________________________
 * INPUT:
 *      operation   : The operation to be performed -> input from
 *                                                     user
 *      num1        : The first number -> input from user
 *      num2        : The second number -> input from user
 *      num3        : The third number -> input from user
 *
 *
 * OUTPUT:
 *      Outputs
 *          - The equation of the given operation and numbers, or
 *            an error if the input is incorrect.
 ****************************************************************/

int main()
{
    // Variables
    string operation; // INPUT - the operation to be performed
    double num1,      // INPUT - the first number
           num2,      // INPUT - the second number
           num3;      // INPUT - the third number

    /* INPUT - receives an operation and either one, two, or three numbers
     *         depending on the operation
     */
    cout << "Please choose an operation: ";
    cin >> operation;
    cout << endl;

    if(operation == "addition" || operation == "subtraction"
            || operation == "multiplication" || operation == "division"
            || operation == "pythagorean" || operation == "quadratic"
            || operation == "sqrt" || operation == "fabs"){
        cout << "Enter your first number: ";
        cin >> num1;
        cout << endl;
    }

    if(operation == "addition" || operation == "subtraction"
         || operation == "multiplication" || operation == "division"
         || operation == "pythagorean" || operation == "quadratic"){

        cout << "Enter your second number: ";
        cin >> num2;
        cout << endl;

    }
    if(operation == "quadratic"){

        cout << "Enter your third number: ";
        cin >> num3;
        cout << endl;
    }

    /* OUTPUT + PROCESSING - Processes the operation and numbers, and
     *                       either outputs the answer, or an error
     *                       if the numbers inputted were mathematically
     *                       incorrect
     */
    if(operation == "addition"){

        cout << "Equation: " << num1 << " + " << num2 << endl << endl;
        cout << "Results: " << num1 + num2 << endl;

    }else if(operation == "subtraction"){

        cout << "Equation: " << num1 << " - " << num2 << endl << endl;
        cout << "Results: " << num1 - num2 << endl;

    } else if(operation == "division"){

        cout << "Equation: " << num1 << " / " << num2 << endl << endl;
        if(num2 != 0.0){
            cout << "Results: " << num1 / num2 << endl;
        } else {
            cout << "Error: Cannot divide by zero." << endl;
        }

    } else if(operation == "multiplication"){

        cout << "Equation: " << num1 << " * " << num2 << endl << endl;
        cout << "Results: " << num1 * num2 << endl;

    } else if(operation == "fabs"){

        cout << "Equation: fabs(" << num1 << ") " << endl << endl;
        cout << "Results: " << fabs(num1) << endl;

    } else if(operation == "sqrt"){

        cout << "Equation: sqrt(" << num1 << ")" << endl << endl;
        if(num1 < 0.0){
            cout << "Error: Cannot take square root of a negative number."
                 << endl;
        } else{
            cout << "Results: " << sqrt(num1) << endl;
        }

    } else if(operation == "quadratic"){

        cout << "Equation: " << num1 << "x^2 + " << num2 << "x + " << num3
             << " = 0" << endl << endl;
        if(pow(num2, 2) - 4 * num1 * num3 < 0){
            cout << "Error: Cannot take square root of a negative number."
                 << endl;
        } else if(num1 == 0.0) {
            cout << "Error: Cannot divide by zero." << endl;
        } else{
            cout << "Results: " << (((-num2) + sqrt(pow(num2, 2) - 4 * num1
                                     * num3)) / (2 * num1)) << ", "
                               << (((-num2) - sqrt(pow(num2, 2) - 4 * num1
                                     * num3)) / (2 * num1)) << endl;
        }

    } else if(operation == "pythagorean"){

        cout << "Equation: sqrt(" << num1 << "^2 + " << num2 << "^2)"
             << endl << endl;
        cout << "Results: " << sqrt(pow(num1, 2) + pow(num2, 2)) << endl;

    } else{

        cout << "Error: Operation not supported." << endl;

    }



    return 0;
}
