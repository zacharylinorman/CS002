#include <string>
#include <vector>
#ifndef HEADER_H
#define HEADER_H

using namespace std;

// CONSTANTS
const int NUM_ROWS = 10; // Number of rows on board
const int NUM_COLS = 10; // Number of columns

const int FLEET_SIZE = 5; // The size of the fleet

// SHIP SIZES
const int CARRIER_SIZE = 5;
const int BATTLESHIP_SIZE = 4;
const int CRUISER_SIZE = 3;
const int SUBMARINE_SIZE = 3;
const int DESTROYER_SIZE = 2;

// CONSTANTS FOR THE DISPLAY BOARD FUNCTION
const string DASHES = "  -----------------------------------------";
const string SPACES = "          ";

// STRUCTURES
struct Point{ // This structure contains a point on a grid
    int r; // The row number
    int c; // The column number
};

struct Ship{ // This structure contins the info for a ship
    string name; // The name of the ship
    int size; // The size of the ship
    int hitCount; // The number of hits the ship has taken
    vector<Point> points; // The points the ship occupies
};

struct PlayerBoard{ // This structure contains a board and a fleet of ships
    char board[NUM_ROWS][NUM_COLS]; // The board
    Ship ships[FLEET_SIZE]; // The fleet of ships
};

struct AI{ // This structure contains the information for an intelligent ai
    // CONSTANTS
    const int targetModeWeight = 35; // The weight for spaces around hit
    // 2 * ( SUM OF SIZES OF SHIPS ) -> HIGHEST POSSIBLE DENSITY SO +1

    // VARIABLES
    PlayerBoard pBoard; // The ai's playerBoard
    int probabilityBoard[NUM_ROWS][NUM_COLS]; // The probability board
    int state; // The ai's mode-> 0: first turn, 1: Hunt, 2: Target
    bool enemyShipSunk[FLEET_SIZE]; // Array of if enemy ships sunk

    // FUNCTIONS
    void resetProbBoard(){ // Resets the probability board
        for(int i = 0; i < NUM_ROWS; i++){
            for(int k = 0; k < NUM_COLS; k++){
                probabilityBoard[i][k] = 0;
            }
        }
    }
};

// PROTOTYPES
/********************************************************************
 * takeTurnAI
 *  This function uses an algorithm to take an intelligent turn for
 *  the ai.
 ********************************************************************/
void takeTurnAI(AI &ai, // The ai
                PlayerBoard &pBoard); // The enemy playerboard

/********************************************************************
 * displayBoard
 *  Displays the two boards, the first being the one who's turn it
 *  is, and the second being the enemy's
 ********************************************************************/
void displayBoards(char p1[][NUM_COLS], // Player's board
                   char p2[][NUM_COLS]);// Enemy's Board

/********************************************************************
 * setShip
 *  Sets a ship to the player board
 ********************************************************************/
void setShip(PlayerBoard &pBoard, // The playerboard
             int shipIndex);      // Index of the ship

/********************************************************************
 * getValidShipInfo
 *  Returns a valid row, column, and orientation to the reference
 *  arguments using a ship index and playerBoard
 ********************************************************************/
void getValidShipInfo(int &r,   // The row number
                      int &c,   // The column number
                      char &orientation, // The orientation
                      const PlayerBoard &pBoard, // The playerboard
                      int ship);  // The ship index

/********************************************************************
 * spaceOccupied
 *  returns true or false depending on whether the ship will overlap
 *  with another already on the board
 ********************************************************************/
bool spaceOccupied(int r, // The starting row number
                   int c, // The starting column number
                   char orientation, // The orientation
                   const PlayerBoard &pBoard, // The playerboard
                   int ship); // The ship index

/********************************************************************
 * initBoard()
 *  Initializes the board for two human players
 ********************************************************************/
void initBoard(PlayerBoard &p1Board,  // Player 1's board
               PlayerBoard &p2Board); // Player 2's board

/********************************************************************
 * initBoard()
 *  Initializes the board for a human player and an ai
 ********************************************************************/
void initBoard(PlayerBoard &p1Board, // Human playerboard
               AI &ai); // The AI

/********************************************************************
 * initFleet()
 *  Initializes the fleet of a playerboard
 ********************************************************************/
void initFleet(PlayerBoard &pBoard); // The playerboard

/********************************************************************
 * initAI()
 *  Initializes an ai object with an already initialized pBoard
 ********************************************************************/
void initAI(AI &ai, // The AI
            PlayerBoard &pBoard); // the playerboard to give to ai

/********************************************************************
 * takeTurn()
 *  Takes the turn for a human player
 ********************************************************************/
void takeTurn(PlayerBoard &pBoard); // The enemy's board

/********************************************************************
 * isGameOver()
 *  Returns true or false depending on whether the given playerboard
 *  has no more ships alive
 ********************************************************************/
bool isGameOver(const PlayerBoard &pBoard);// The playerboard to check


#endif // HEADER_H
