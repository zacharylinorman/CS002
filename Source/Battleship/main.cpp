/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Battleship
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 2/13/19
 ****************************************************************/
#include <iostream>
#include "header.h"

using namespace std;
/****************************************************************
 * Battleship
 * ______________________________________________________________
 * This program simulates the game of battleship. The user has
 * the choice of whether to play against an intelligent bot, or
 * against another player.
 * ______________________________________________________________
 * INPUT:
 *      playAIC     - Whether to play against the intelligent bot
 *      r           - The row of the board
 *      c           - The column of the board
 *
 * OUTPUT:
 *      The game.
 ****************************************************************/

int main()
{
    // VARIABLES
    PlayerBoard player1; // The PlayerBoard object for player 1
    PlayerBoard player2; // The PlayerBoard object for player 2
    bool gameFinished;   // Is the game over?

    AI ai;               // The AI object
    bool playAI;         // Whether to play against the intelligent bot
    char playAIC;        // The input char

    // INITIALIZING
    initFleet(player1);  // Initialize player 1's fleet
    initFleet(player2);  // Initialize player 2's fleet

    // INPUT - receieve whether to play against bot or not
    do{
        cout << "Would you like to play against a bot (enter y or n)? ";
        cin >> playAIC;
        cout << endl;
    }while(!(tolower(playAIC) == 'y' || tolower(playAIC) == 'n'));

    // Set playAI to true or false
    if(playAIC == 'y'){
        playAI = true;
    } else{
        playAI = false;
    }

    // If playAI, intialize the ai and the board with ai
    if(playAI){
        initAI(ai, player2);
        initBoard(player1, ai);
    }else{ // Otherwise just initialize the board with two players
        initBoard(player1, player2);
    }

    cout << endl << endl << endl;

    // The game has not been finished yet
    gameFinished = false;

    // GAME LOOP
    do{
        if(playAI){ // Against ai

            cout << "Player 1:" << endl;
            takeTurn(ai.pBoard); // Player 1 takes turn
            displayBoards(player1.board, ai.pBoard.board); // Prints board
            gameFinished = isGameOver(ai.pBoard);  // Is the game over?

            if(!gameFinished){ // Continue to ai's turn if game isn't over
                cout << "Player 2 (AI):" << endl;
                takeTurnAI(ai, player1); // AI takes turn
                displayBoards(ai.pBoard.board, player1.board);
                gameFinished = isGameOver(player1); // Is game over?
            }

        }else{ // Two human players

            cout << "Player 1:" << endl;
            takeTurn(player2); // Player 1 takes turn
            displayBoards(player1.board, player2.board); // Prints board
            gameFinished = isGameOver(player2); // Is the game over?

            if(!gameFinished){ // Continue to p2's turn if game isn't over
                cout << "Player 2:" << endl;
                takeTurn(player1); // Player 2 takes turn
                displayBoards(player2.board, player1.board);
                gameFinished = isGameOver(player1); // The game over?
            }

        }
    } while(!gameFinished); // Continue as long as game is not over

    // OUTPUT - congratulatory message
    cout << "You sunk the fleet!!! You win!!!" << endl;

    return 0;
}
