/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Hangman
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/23/19
 ****************************************************************/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/****************************************************************
 * Hangman
 * ______________________________________________________________
 * This program simulates the game of hangman. One player chooses
 * a phrase for the other player to guess. The phrase is shown as
 * dashes and puncation marks to the guessing player, and the
 * guessing player has 7 chances to select letters of which they
 * think might be part of the phrase. If the guessing player
 * successfully fills out the phrase, they win. If they use up
 * their 7 chances, they lose.
 * ______________________________________________________________
 * FUNCTIONS:
 *      setupUnsolved(string)   : Puts dashes in place of alphabetic
 *                                characters in the phrase.
 *
 *      updateUnsolved(string, string, char)
 *                              : Replaces the dashes with the guessed
 *                                character.
 *
 *      getGuess(string)        : Gets valid guess as input.
 *
 *                                   -A guess is taken as input as a
 *                                    character. It is valid if
 *                                       1) it is an alphabetic character;
 *                                          and
 *                                       2) the character has not already
 *                                          been guessed
 * INPUT:
 *      phrase      : The phrase to be guessed
 *      guess       : The guessed character
 *
 * OUTPUT:
 *
 *
 ****************************************************************/


// PROTOTYPES

/// @brief Puts dashes in place of alphabetic characters in the phrase.
/// @param phrase the phrase to be solved
/// @return the phrase with all alphabetic characters converted to dashes
string setupUnsolved(string phrase);


/// @brief Replaces the dashes with the guessed character.
/// @param phrase the phrase to be solved
/// @param unsolved the phrase with dashes for all unsolved characters
/// @param guess the char containing the current guessed character
/// @return the new unsolved string with dashes replaced by new guess
string updateUnsolved(string phrase, string unsolved, char guess);


/// @brief Gets valid guess as input.
///
///    A guess is taken as input as a character. It is valid if
///    1) it is an alphabetic character; and
///    2) the character has not already been guessed
///
/// @param prevGuesses the string containing all characters guessed so far
/// @return a valid guess and only a valid guess as a character
char getGuess(string prevGuesses);


int main()
{
    // VARIABLES
    string phrase, // The phrase to be guessed
           puzzle; // The unsolved phrase variable

    char guess;    // The guessed character

    string prevGuesses;   // The characters already guessed
    int wrongGuessesLeft; // The number of guesses remaining

    bool finished;// Whether the phrase has been guessed or not

    // INPUT - receiving phrase
    cout << "Enter phrase: ";
    getline(cin, phrase);
    cout << endl;

    //system("CLS"); - commented out for hypergrade


    // PROCESSING - use setupUnsolved to create the puzzle
    puzzle = setupUnsolved(phrase);

    // OUTPUT - shows the unsolved puzzle
    cout << "Phrase: " << puzzle << endl;

    // PROCESSING - initialize variables
    finished = false;
    prevGuesses = "";
    wrongGuessesLeft = 7;

    // As long as the puzzle has not been solved and guesses are left
    while(!finished && wrongGuessesLeft > 0)
    {
        if(prevGuesses.size()>0) // Is this the first guess?
        {
            // OUTPUT - shows info of the state of the game
            cout << "Guessed so far: " << prevGuesses << endl;
            cout << "Wrong guesses left: " << wrongGuessesLeft << endl;
            cout << /*"Phrase: " <<*/ puzzle << endl << endl;//HYPERGRADE
        }

        // INPUT - receive valid guess using getGuess
        guess = getGuess(prevGuesses);

        // PROCESSING - add the guess to the previous guesses
        prevGuesses += guess;

        // If the puzzle remains the same after updating, guess is wrong
        if(puzzle == updateUnsolved(phrase, puzzle, guess))
        {
            wrongGuessesLeft--;
        }else // Otherwise update the puzzle
        {
            puzzle = updateUnsolved(phrase, puzzle, guess);

            // If the puzzle matches the phrase, win!!
            if(puzzle == phrase)
            {
                finished = true;
            }
        }
        //system("CLS");
    }
    if(finished) // Phrase has been guessed!!
    {
        // OUTPUT - final game state & congratulatory message
        cout << "Guessed so far: " << prevGuesses << endl;
        cout << "Wrong guesses left: " << wrongGuessesLeft << endl;
        cout <<  puzzle << endl << endl;
        cout << "Congratulations!! You won!" << endl;
    }else // Ran out of guesses :(
    {
        // OUTPUT - :(
        cout << "You lost!" << endl;
    }
    return 0;
}

/// @brief Puts dashes in place of alphabetic characters in the phrase.
/// @param phrase the phrase to be solved
/// @return the phrase with all alphabetic characters converted to dashes
string setupUnsolved(string phrase)
{
    for(int i = 0; i < phrase.size(); i++) // Iterate through the phrase
    {
        // If the character is a letter, change it to a dash
        if(tolower(phrase.at(i)) <= 'z' && tolower(phrase.at(i)) >= 'a' )
            phrase.at(i) = '-';
    }
    return phrase; // return the changed phrase
}

/// @brief Replaces the dashes with the guessed character.
/// @param phrase the phrase to be solved
/// @param unsolved the phrase with dashes for all unsolved characters
/// @param guess the char containing the current guessed character
/// @return the new unsolved string with dashes replaced by new guess
string updateUnsolved(string phrase, string unsolved, char guess)
{
    for(int i = 0; i < phrase.size(); i++) // Iterate through the phrase
    {
        // If the character matches the guess
        if(tolower(phrase.at(i)) == guess)
        {
            unsolved.at(i) = phrase.at(i); // Reveal it in the phrase
        }
    }
    return unsolved;
}

/// @brief Gets valid guess as input.
///
///    A guess is taken as input as a character. It is valid if
///    1) it is an alphabetic character; and
///    2) the character has not already been guessed
///
/// @param prevGuesses the string containing all characters guessed so far
/// @return a valid guess and only a valid guess as a character
char getGuess(string prevGuesses)
{
    // VARIABLE
    char guess; // The guessed character
    bool validGuess; // Is the guess valid?

    // INPUT - receive the guess
    cout << "Enter a guess: ";
    cin >> guess;
    cout << endl;

    do
    {
        validGuess = true; // Assume guess is valid until proven otherwise
        if(guess > 'z' || guess < 'a') // Is the guess a lowercase letter?
        {
            // OUTPUT & INPUT - If not, make user re-enter a guess
            cout << "Invalid guess! Please re-enter a guess: ";
            cin >> guess;
            cout << endl;
            validGuess = false; // Guess is not valid- continue to loop
        }else // The guess is a lowercase character
        {
            // Iterate through previous guesses
            for(int i = 0; i < prevGuesses.size(); i++)
            {
                // If the guess has already been guessed
                if(prevGuesses.at(i) == guess)
                {
                    // OUTPUT & INPUT - Make user re-enter a guess
                    cout << "Invalid guess! Please re-enter a guess: ";
                    cin >> guess;
                    cout << endl;
                    validGuess = false; // Guess is not valid
                    break; // No need to go through rest of prev guesses
                }
            }
        }
    }while(!validGuess); // Continue as long as guess is not valid
    return guess;
}
