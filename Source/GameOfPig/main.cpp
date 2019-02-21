/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Game of Pig
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/16/19
 ****************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

/****************************************************************
 * Game of Pig
 * ______________________________________________________________
 * This program simulates a turn of the Game of Pig a user-
 * inputted N times to calculate the probability of the possible
 * outcome of the user-inputted hold value.
 * ______________________________________________________________
 * INPUT:
 *      holdValue       : The value to hold at for the turn
 *      numSimulations  : The number of turns to simulate
 *
 *
 * OUTPUT:
 *      Output:
 *          This program outputs a table of probabilities using
 *          the outcomes of the simulated turns.
 ****************************************************************/

int main()
{

    // VARIABLES

    int holdValue,      // INPUT - The value to hold at for the turn
        numSimulations; // INPUT - The number of turns to simulate

    int score; // PROCESSING - the variable used to find the turn's score

    /* PROCESSING VARIABLES - These variables are used for the probability
     *                        calculations. They are the possible scores
     *                        for the user's hold value.
     */
    int possibleScore1, possibleScore2, possibleScore3, possibleScore4,
            possibleScore5, possibleScore6, possibleZero;


    // INPUT - receive the hold value and number of simulations from user
    cout << "What value should we hold at? ";
    cin >> holdValue;
    cout << endl;

    cout << "Hold-at-N turn simulations? ";
    cin >> numSimulations;
    cout << endl;



    srand(333); // Set the seed for the random number generator

    // PROCESSING - simulate turns and count each outcome
    // initialize processing variables
    possibleScore1 = possibleScore2 = possibleScore3 = possibleScore4
            = possibleScore5 = possibleScore6 = possibleZero = 0;

    for(int i = 0; i < numSimulations; i++){
        score = 0; // reset score value each turn iteration
        while(score < holdValue){ // the turn
            int randValue = rand() % 6 + 1;
            if(randValue != 1){
                score += randValue;
            }else{
                score = 0;
                break;
            }
        }
        // increment the corresponding outcome's count
        if(score == 0){
            possibleZero++;
        }else if(score == holdValue){
            possibleScore1++;
        }else if(score == holdValue + 1){
            possibleScore2++;
        }else if(score == holdValue + 2){
            possibleScore3++;
        }else if(score == holdValue + 3){
            possibleScore4++;
        }else if(score == holdValue + 4){
            possibleScore5++;
        }else if(score == holdValue + 5){
            possibleScore6++;
        }
    }
    cout.precision(6); // set and fix the precision of the probabilities
    cout << fixed;


    /* OUTPUT & PROCESSING - output the table of probabilities by casting
     *                       the count of each outcome to a double, then
     *                       dividing by the number of simulations.
     */
    cout << "Score\tEstimated Probability" << endl;

    cout << "0\t" << static_cast<double>(possibleZero) / numSimulations
         << endl;
    cout << holdValue << "\t"
         << static_cast<double>(possibleScore1) / numSimulations << endl;
    cout << holdValue + 1 << "\t"
         << static_cast<double>(possibleScore2) / numSimulations << endl;
    cout << holdValue + 2 << "\t"
         << static_cast<double>(possibleScore3) / numSimulations << endl;
    cout << holdValue + 3 << "\t"
         << static_cast<double>(possibleScore4) / numSimulations << endl;
    cout << holdValue + 4 << "\t"
         << static_cast<double>(possibleScore5) / numSimulations << endl;
    cout << holdValue + 5 << "\t"
         << static_cast<double>(possibleScore6) / numSimulations << endl;


    return 0;
}
