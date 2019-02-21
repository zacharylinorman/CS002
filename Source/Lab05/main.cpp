/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Lab 05
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/15/19
 ****************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
/****************************************************************
 * Lab 05
 * ______________________________________________________________
 * This program has three different exercises. Exercise 1 prints
 * out 3 different outputs. The first is an incremental count
 * using two bounds given by the user. The second is an every-
 * other count using two bounds given by the user. The third is
 * an count using two bounds given by the user the multiplies the
 * previous term by -2. Exercise 2 allows the user to enter a
 * list of scores, then outputs how many of each letter grade
 * exists in the list. Exercise 3 continues to flips a coin until
 * the user does not want to anymore.
 * ______________________________________________________________
 * INPUT:
 *      ex           : The exercise number
 *      Exercise 1:
 *          beginning: The lower bound
 *          end      : The upper bound
 *      Exercise 2:
 *          num      : The score to be counted
 *      Exercise 3:
 *          choice   : User's choice to continue
 *
 *
 * OUTPUT:
 *      Exercise 1:
 *          1. Increment numbers in bounds
 *          2. Every-other number in bounds
 *          3. -2*previous number in bounds
 ****************************************************************/

int main()
{
    // VARIABLES
    int ex; // INPUT - The exercise number

    // INPUT - receive exercise number
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    // PROCESSING - controls which exercise to run
    if(ex == 1){
        // Exercise 1

        // VARIABLES
        int beginning, // INPUT - The lower bound
            end;       // INPUT - the upper bound

        // INPUT - receive the bounds
        cout << "Enter beginning and ending numbers, separated by space: ";
        cin >> beginning >> end;
        cout << endl;

        // PROCESSING & OUTPUT - Increments from lower bound to output
        for(int i = beginning; i <= end; i++){
            cout << i;
            if(i < end)
                cout << ", ";
        }
        cout << endl;

        // INPUT - receive the bounds
        cout << "Enter beginning and ending numbers, separated by space: ";
        cin >> beginning >> end;
        cout << endl;

        // PROCESSING & OUTPUT - Every other from lower bound to output
        for(int i = beginning; i <= end; i+=2){
            cout << i;
            if(i+2 <= end)
                cout << ", ";
        }
        cout << endl;

        // INPUT - receive the bounds
        cout << "Enter the beginning and largest positive numbers, "
                "separated by space: ";
        cin >> beginning >> end;
        cout << endl;

        // PROCESSING & OUTPUT - Previous * -2 from lower bound to output
        for(int i = beginning; abs(i) <= end; i*=-2){
            cout << i;
            if(i < end)
                cout << ", ";
        }
        cout << endl;


    }else if(ex == 2){
        // Exercise 2

        // VARIABLES
        int a, b, c, d, f, // PROCESSING - the counts for each letter grade
                num; // INPUT - The score to add to list

        // PROCESSING - Initializing variables
        a = b = c = d = f = num = 0;

        // PROCESSING & INPUT - receives each score to add to list

        while(num != -1){// Sentinel-controlled - exits on receiving -1
            cout << "Enter one or more grades, or -1 to stop: " << endl;
            cin >> num;
            if(num < 0){
                continue;
            }else if(num < 60){
                f++;
            }else if(num < 70){
                d++;
            }else if(num < 80){
                c++;
            }else if(num < 90){
                b++;
            }else{
                a++;
            }
        }

        // OUTPUT - outputs the counts of the letter grades
        cout << "The grades breakdown is: " << endl;
        cout << "As: " << a << endl;
        cout << "Bs: " << b << endl;
        cout << "Cs: " << c << endl;
        cout << "Ds: " << d << endl;
        cout << "Fs: " << f << endl;

    }else if(ex == 3){
        // Exercise 3

        // VARIABLES
        string choice; // INPUT - User's choice to continue

        // PROCESSING - initializing variables
        choice = "yes";

        /* PROCESSING & INPUT & OUTPUT - Receives user's choice. If yes,
         *                               randomly generates either a 1 or 0
         *                               1 -> print heads. 0 -> pring tails
         *                               If not yes, exit progam.
         */
        while(choice == "yes"){ // Sentinel-controlled
            // INPUT
            cout << "Toss the coin? ";
            cin >> choice;
            cout << endl;

            // PROCESSING & OUTPUT
            if(choice == "yes"){
                if(rand()%2){ // Randomly generate either 1 or 0
                    cout << "tails" << endl;
                }else{
                    cout << "heads" << endl;
                }
            }

        }
    }

    return 0;
}
