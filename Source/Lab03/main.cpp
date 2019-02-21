/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Lab 03
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/10/19
 ****************************************************************/

#include <iostream>

using namespace std;

/****************************************************************
 * LAB 02
 * ______________________________________________________________
 * This program either translates seconds, or gives the user a
 * response.
 * ______________________________________________________________
 * INPUT:
 *      ex              : The exercise number -> input from user
 *      numberOfSeconds : The number of seconds -> input from user
 *      option          : The option -> input from user
 *
 * OUTPUT:
 *      If the user enters 1 for ex:
 *          The program outputs the number of seconds in minutes, hours,
 *          or days.
 *      If the user enters 2 for ex:
 *          A response is generated based on user input.
 ****************************************************************/
int main()
{
    // Variables
    int ex;     // INPUT - The exercise number

    // INPUT - Receiving the exercise number from user
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    // PROCESSING - if-block running either exercise 1 or 2 based on ex
    if (ex == 1){
        // All Exercise 1 code

        // VARIABLES
        int numberOfSeconds; // INPUT - The number of seconds

        // INPUT - Receiving the number of seconds
        cout << "Enter a number of seconds: ";
        cin >> numberOfSeconds;
        cout << endl;

        // PROCESSING & OUTPUT
        if(numberOfSeconds < 60){ // seconds

            if(numberOfSeconds == 1){
                cout << "There is " << numberOfSeconds << " second in ";
            } else{
                cout << "There are " << numberOfSeconds << " seconds in ";
            }
            cout << numberOfSeconds << " seconds." << endl;

        } else if(numberOfSeconds < 3600){ // minutes

            if(numberOfSeconds/ 60  == 1){
                cout << "There is " << (numberOfSeconds / 60)
                     << " minute in ";
            } else{
                cout << "There are " << (numberOfSeconds / 60)
                     << " minutes in ";
            }
            cout  << numberOfSeconds << " seconds." << endl;

        } else if(numberOfSeconds < 86400){ // hours

            if(numberOfSeconds / 3600 == 1){
                cout << "There is " << (numberOfSeconds / 3600)
                     << " hour in " ;
            } else{
                cout << "There are " << (numberOfSeconds / 3600)
                     << " hours in " ;
            }
            cout << numberOfSeconds << " seconds." << endl;
        } else{ // days

            if(numberOfSeconds / 86400 == 1){
                cout << "There is " << (numberOfSeconds / 86400)
                     << " day in " ;
            } else{
                cout << "There are " << (numberOfSeconds / 86400)
                     << " days in " ;
            }
            cout << numberOfSeconds << " seconds." << endl;

        }


    } else if(ex == 2){
        // All Exercise 2 code

        // VARIABLES
        char option;

        // INPUT
        cout << "What do you want to do tonight?" << endl
             << "a. Go to the movies" << endl
             << "b. Eat out" << endl
             << "c. Hang out at the Mall" << endl
             << "d. Go watch the Dodgers";
        cin >> option;
        cout << endl;


        //OUTPUT & PROCESSING
        if(option == 'a' || option == 'A'){

            cout << "I know just the movie to see!" << endl;

        } else if(option == 'b' || option == 'B'){

            cout << "Great! I've been wanting to try "
                    "that new Tuvaluan restaurant!" << endl;

        } else if(option == 'c' || option == 'C'){

            cout << "You bring the cash!" << endl;

        } else if(option == 'd' || option == 'D'){

            cout << "Take me out to the ball game ..." << endl;

        } else{

            cout << "Nothing suits you, then? "
                    "I guess we'll just stay and program!" << endl;

        }
    }
    return 0;
}
