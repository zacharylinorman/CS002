/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Tic Tac Toe
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 2/6/19
 ****************************************************************/
#include <vector>
#include <iostream>

using namespace std;

/****************************************************************
 * Tic Tac Toe
 * ______________________________________________________________
 * This program simulates the game of tic tac toe. Two players
 * alternate choosing a position on the board to place their
 * marker. If one of them gets three of their marker in a row,
 * column, or diagonal, they win. If the board becomes full, with
 * no one winning, it is a tie.
 * ______________________________________________________________
 * INPUT:
 *      getPlay()       : The position on the board for the play
 *
 * OUTPUT:
 *      The state of the board is outputted, as well as the
 *      proper end-of-game messages.
 ****************************************************************/

// PROTOTYPES

/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen();

/// @brief Draws the provided tic-tac-toe board to the screen
///  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector <char> &board); // The game board

/// @brief Fills vector with characters starting at lower case a.
///
///     The amount of the alphabet placed into the vector depends on its size.
///     When the vector is size 1 then it will have only character a.
///     When the vector is size 5 then it will have characters a to e.
///     When the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v); // The vector to initialize

int convertPosition(char position); // The char to convert

bool validPlacement(const vector <char> &board, // The game board
                    int position); // The position to check

int getPlay(const vector <char> &board); // The game board

bool gameWon(const vector <char> &board); // The game board

bool boardFull(const vector <char> &board); // The game board

// GLOBAL CONSTANTS
const bool CLEAR_SCREEN = true; // Whether to clear the screen or not

// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main()
{
    // VARIABLES
    vector <char> board(9); // The game board
    int turn = PLAYER1; // Player 1 always goes first and is 'x'

    // Initialize board to empty state
    initVector(board);

    // Display empty board
    drawBoard(board);

    // PROCESSING - Take turns to fill board using getPlay
    do{
        if(turn == PLAYER1){
            board[getPlay(board)] = 'x'; // Get the play
            turn = PLAYER2; // Switch to player 2
        }else if(turn == PLAYER2){
            board[getPlay(board)] = 'o'; // Get the play
            turn = PLAYER1; // Switch to player 1
        }
        drawBoard(board); // Draw updated board
     // Continue as long as no one has won and there are still spaces
    }while(!(gameWon(board) || boardFull(board)));

    // OUTPUT - output the game results
    if(boardFull(board) && !gameWon(board)){ // Tie!
        cout << "No one wins." << endl;
    }else if(turn){ // Player 1 wins
        cout << "Player 1 wins!!" << endl;
    }else{ // Player 2 wins
        cout << "Player 2 wins!!" << endl;
    }
    return 0;
}


/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen()
{
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
        //  system("CLS");
    }

    cout << endl;
}


/// @brief Draws the provided tic-tac-toe board to the screen
///  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector <char> &board)
{
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << board.at(i) << "  |  " << board.at(i + 1) << "  |  "
            << board.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     The amount of the alphabet placed into the vector depends on its size.
///     When the vector is size 1 then it will have only character a.
///     When the vector is size 5 then it will have characters a to e.
///     When the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v)
{
    for(int i = 0; i < v.size(); i++){ // Loop through the vector
        v[i] = 'a' + i; // a starts at 0, then goes through alphabet
    }
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char position)
{
    return position - 'a'; // 'a' would be 0 -> for vector indexes
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector <char> &board, int position)
{
    // If there is no x or o and the board contains the position
    return (board[position] != 'x'
            && board[position] != 'o'
            && position < board.size());
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector <char> &board)
{
    char pos; // Temparary position variable
    do{
        // INPUT- ask user for the position
        cout << "Please choose a position: ";
        cin >> pos;
        cout << endl;
        // Continue if invalid placement
    } while(!validPlacement(board, convertPosition(pos)));

    // Convert to an integer position and return
    return convertPosition(pos);
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board
/// @return true if the game has been won, false otherwise
bool gameWon(const vector <char> &board)
{
    // Loop through the board (technically only need up until index 6)
    for(int i = 0; i < board.size(); i++){
        // Separate by rows, columns and diagonals
        if(i % 3 == 0 || i == 0){ // ROWS
            if(board[i] == 'x' && board[i + 1] == 'x'
                    && board[i + 2] == 'x'){
                return true;
            }else if(board[i] == 'o' && board[i + 1] == 'o'
                     && board[i + 2] == 'o'){
                return true;
            }
        }
        if(i<3){ // COLUMNS
            if(board[i] == 'x' && board[i + 3] == 'x'
                    && board[i + 6] == 'x'){
                return true;
            }else if(board[i] == 'o' && board[i + 3] == 'o'
                     && board[i + 6] == 'o'){
                return true;
            }
        }
        if(i == 0 || i == 2){ // DIAGONALS
            if(board[i] == 'x' && board[4 - i] == 'x'
                    && board[8 - i] == 'x'){
                return true;
            }else if(board[i] == 'o' && board[4 - i] == 'o'
                    && board[8 - i] == 'o'){
                return true;
            }
        }
    }
    return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector <char> &board)
{
    for(int i = 0; i < board.size(); i++){ // Loop through board
        // If there is anything other than an x or o, still has space
        if(!(board[i] == 'x' || board[i] == 'o'))
            return false;
    }
    // Went through entire board, no empty spaces
    return true;
}

