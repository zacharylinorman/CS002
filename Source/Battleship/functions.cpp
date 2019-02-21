#include "header.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/********************************************************************
 * initAI()
 *  Initializes an ai object with an already initialized pBoard
 ********************************************************************/
void initAI(AI &ai, PlayerBoard &pBoard){
    //srand(time(0)); // Randomize random seed
    srand(500); // Set random sed for testing purposes
    ai.pBoard = pBoard; // Set's ai's board to the playerboard given
    ai.resetProbBoard(); // Initialize probability board
    ai.state = 0; // Initialize state to 0

    // Initialize the array of sunken ships to all false
    for(int i = 0; i < FLEET_SIZE; i++){
        ai.enemyShipSunk[i] = false;
    }
}

/********************************************************************
 * takeTurnAI
 *  This function uses an algorithm to take an intelligent turn for
 *  the ai.
 ********************************************************************/
void takeTurnAI(AI &ai, PlayerBoard &pBoard){
    // VARIABLES
    int r,       // Row number
        c,       // Column number
        maxProb; // The highest density on probability board
    r = c = maxProb = 0; // Initialize to 0
    ai.resetProbBoard(); // Reset the probability board

    switch(ai.state){
    case 0: // FIRST TURN - No info yet, so shot semi-randomly using parity
        r = rand() % (NUM_ROWS / 2) * 2;     // Even number
        c = rand() % (NUM_COLS / 2) * 2 + 1; // Odd number

        // Now check for hit or miss

        // If it is a hit
        if(pBoard.board[r][c] == 's'){
            cout << "Hit!!!" << endl;
            pBoard.board[r][c] = 'H';

            // Find which ship was hit, and increment its hitcount
            bool foundShip = false;

            // Loop throuhg fleet
            for(int i = 0; i < FLEET_SIZE; i++){

                // If ship has not been sunk yet
                if(!ai.enemyShipSunk[i]){

                    // Loop through points
                    for(int k = 0; k < pBoard.ships[i].points.size(); k++){

                        // If point matches with shot
                        if(pBoard.ships[i].points[k].r == r &&
                                pBoard.ships[i].points[k].c == c){

                            // Increment hitcount
                            pBoard.ships[i].hitCount++;

                            // First turn- no need to check if sunk
                            foundShip = true;
                            break;
                        }
                    }
                }
                // Ship was found, break out of loop
                if(foundShip){
                    break;
                }
            }
            ai.state = 2; // There is an actve hit, go to target mode
        }else{ // Missed
            cout << "You Missed." << endl;
            pBoard.board[r][c] = 'M';
            ai.state = 1; // There are no active hits, go to hunt mode
        }
        break;
    case 1: // HUNT MODE
        // For debugging: cout << "Hunt mode" << endl;

        // BUILD THE PROBABILITY BOARD FOR HUNT MODE
        // ASSUME ALL HITS ARE PART OF SUNKEN SHIPS IN THIS MODE

        // Loop through the fleet to check for where each ship fits
        for(int i = 0; i < FLEET_SIZE; i++){

            // If the ship has not been sunk
            if(!ai.enemyShipSunk[i]){

                // Create a temporary size variable
                int s = pBoard.ships[i].size;

                // HORIZONTAL
                // Loop through the board
                for(int k = 0; k < NUM_ROWS; k++){
                    for(int j = 0; j < NUM_COLS-s+1; j++){

                        // Assume fits until proven otherwise
                        bool fits = true;

                        // Loop through the points in the ship
                        for(int p = 0; p < s; p++){

                            // If the ship overlaps a spot that is hit
                            // or miss, then it does not fit in this spot
                            if(pBoard.board[k][j+p] == 'H' ||
                               pBoard.board[k][j+p] == 'M'){
                                fits = false;
                                break;
                            }
                        }

                        // If it fits
                        if(fits){

                            // Loop through the points to increment its
                            // count on the probability board
                            for(int p = 0; p < s; p++){
                                ai.probabilityBoard[k][j+p]++;
                            }
                        }
                    }
                }


                // VERTICAL
                // Loop through the board
                for(int k = 0; k < NUM_ROWS-s+1; k++){
                    for(int j = 0; j < NUM_COLS; j++){

                        // Assume fits until proven otherwise
                        bool fits = true;

                        // Loop through the points in the ship
                        for(int p = 0; p < s; p++){

                            // If the ship overlaps a spot that is hit
                            // or miss, then it does not fit in this spot
                            if(pBoard.board[k+p][j] == 'H' ||
                               pBoard.board[k+p][j] == 'M'){
                                fits = false;
                                break;

                            }
                        }

                        // If it fits
                        if(fits){

                            // Loop through the points to increment its
                            // count on the probability board
                            for(int p = 0; p < s; p++){
                                ai.probabilityBoard[k+p][j]++;
                            }
                        }
                    }
                }

            }
        }

        // FIND THE SPOT ON THE PROBABILITY BOARD WITH THE HIGHEST
        // PROBABILITY OF A SHIP BEING THERE

        // Loop through the board to find highest
        for(int i = 0; i < NUM_ROWS; i++){
            for(int j = 0; j < NUM_COLS; j++){
                if(ai.probabilityBoard[i][j] > maxProb){
                    maxProb = ai.probabilityBoard[i][j];
                    r = i;
                    c = j;
                }
            }
        }

        // If it is a hit
        if(pBoard.board[r][c] == 's'){
            cout << "Hit!!!" << endl;
            pBoard.board[r][c] = 'H';

            // Loop through fleet to find which ship was hit
            bool foundShip = false;
            for(int i = 0; i < FLEET_SIZE; i++){ // Loop through fleet

                // If the ship has not been sunk
                if(!ai.enemyShipSunk[i]){

                    // Loop through its points
                    for(int k = 0; k < pBoard.ships[i].points.size(); k++){

                        // If the point matches the shot
                        if(pBoard.ships[i].points[k].r == r &&
                           pBoard.ships[i].points[k].c == c){

                            // Increment the hitcount
                            pBoard.ships[i].hitCount++;
                            foundShip = true;

                            // NO NEED TO CHECK IF SHIP SUNK B/C HIT
                            // A NEW SHIP
                            break;
                        }
                    }
                }
                if(foundShip){
                    break;
                }
            }

            // BECAUSE HIT A NEW SHIP, THERE IS NOW AN 'H' ON THE BOARD
            // THAT IS NOT PART OF A SUNKEN SHIP. SWITCH TO TARGET MODE
            ai.state = 2;
        }else{ // Missed
            cout << "You Missed." << endl;
            pBoard.board[r][c] = 'M';
        }

        break;

    case 2: // TARGET MODE
        // For debugging: cout << "Target mode" << endl;

        // TARGET MODE - BUILD THE PROBABILITY BOARD- WHEN FITTING THE
        // SHIPS NEED TO CHECK TO SEE IF AN 'H' IS PART OF AN ALREADY
        // SUNKEN SHIP. IF IT IS NOT, ADD A HEAVY WEIGHT TO THE TILES
        // SURROUNDING BECAUSE AT LEAST ONE OF THEM IS PART OF A SHIP

        // Loop through each ship to see if it fits in spaces in board
        for(int i = 0; i < FLEET_SIZE; i++){

            // If the ship has not been sunk yet
            if(!ai.enemyShipSunk[i]){

                // Temp variable for size of the ship
                int s = pBoard.ships[i].size;


                // HORIZONTAL:

                // Loop through the board
                for(int k = 0; k < NUM_ROWS; k++){
                    for(int j = 0; j < NUM_COLS-s+1; j++){

                        // Temp variable for breaking out of loops
                        bool fits = true;

                        // Loop through points on ship
                        for(int p = 0; p < s; p++){

                            // If it overlaps with a hit
                            if(pBoard.board[k][j+p] == 'H'){

                                // Loop through all of the enemy ships
                                for(int o = 0; o < FLEET_SIZE; o++){

                                    // Check if it has been sunk yet
                                    if(ai.enemyShipSunk[o]){
                                        // Yes, it has been sunk

                                        // Loop through the points on the enemy ship
                                        for(int q = 0; q < pBoard.ships[o].points.size(); q++){

                                            // If it is where the hit is, ship has been sunk, so does not fit
                                            if(k == pBoard.ships[o].points[q].r && j == pBoard.ships[o].points[q].c){
                                                fits = false;
                                                break;
                                            }
                                        }
                                    }
                                    if(!fits){
                                        break;
                                    }
                                }
                            }else if(pBoard.board[k][j+p] == 'M'){
                                // Ran into a miss, doesn't fit
                                fits = false;
                            }
                            if(!fits){
                                break;
                            }
                        }
                        // The ship fits!! Update the probability board
                        if(fits){

                            // Loop through the points of the ship
                            for(int p = 0; p < s; p++){

                                // If it went over a hit, we know that one
                                // of the adjacent tiles is part of the ship
                                if(pBoard.board[k][j+p] == 'H'){
                                    // Add the heavy weight to each adjacent tile
                                    // that is part of the orientation
                                    // If it is on the board

                                    if(j+p+1 < NUM_COLS){
                                        if(pBoard.board[k][j+p+1] != 'H' && pBoard.board[k][j+p+1] != 'M'){
                                            ai.probabilityBoard[k][j+p+1] += ai.targetModeWeight;
                                            if(j+p-1 >= 0){
                                                if(pBoard.board[k][j+p-1] == 'H'){ // On same line
                                                    ai.probabilityBoard[k][j+p+1] *= 2;
                                                }
                                            }
                                        }
                                    }

                                    if(j+p-1 >= 0){
                                        if(pBoard.board[k][j+p-1] != 'H' && pBoard.board[k][j+p-1] != 'M'){
                                            ai.probabilityBoard[k][j+p-1] += ai.targetModeWeight;
                                            if(j+p+1 < NUM_COLS){
                                                if(pBoard.board[k][j+p+1] == 'H'){ // On same line
                                                    ai.probabilityBoard[k][j+p-1] *= 2;
                                                }
                                            }
                                        }
                                    }
                                }else{
                                    // Otherwise just increment the spot
                                    ai.probabilityBoard[k][j+p]++;
                                }
                            }
                        }
                    }
                }

                // VERTICAL:
                // Same deal as horizontal, except this time trying to
                // fit the ship with vertical orientation

                // Board loop
                for(int k = 0; k < NUM_ROWS-s+1; k++){
                    for(int j = 0; j < NUM_COLS; j++){

                        bool fits = true;
                        for(int p = 0; p < s; p++){ // Point loop

                            // Check for overlap sunken
                            if(pBoard.board[k+p][j] == 'H'){
                                for(int o = 0; o < FLEET_SIZE; o++){
                                    if(ai.enemyShipSunk[o]){
                                        for(int q = 0; q < pBoard.ships[o].points.size(); q++){
                                            if(k == pBoard.ships[o].points[q].r && j == pBoard.ships[o].points[q].c){
                                                fits = false;
                                                break;
                                            }
                                        }
                                    }
                                    if(!fits){
                                        break;
                                    }
                                }
                            }else if(pBoard.board[k+p][j] == 'M'){
                                // Overlaps a miss, does not fit
                                fits = false;
                            }
                            if(!fits){
                                break;
                            }
                        }
                        if(fits){
                            for(int p = 0; p < s; p++){ // Point loop

                                // Add to probability board accordingly
                                if(pBoard.board[k+p][j] == 'H'){
                                    if(k+p+1 < NUM_ROWS){
                                        if(pBoard.board[k+p+1][j] != 'H' && pBoard.board[k+p+1][j] != 'M'){
                                            ai.probabilityBoard[k+p+1][j] += ai.targetModeWeight;
                                            if(k+p-1 >= 0){
                                                if(pBoard.board[k+p-1][j] == 'H'){
                                                    ai.probabilityBoard[k+p+1][j] *= 2;
                                                }
                                            }
                                        }
                                    }

                                    if(k+p-1 >= 0){
                                        if(pBoard.board[k+p-1][j] != 'H' && pBoard.board[k+p-1][j] != 'M'){
                                            ai.probabilityBoard[k+p-1][j] += ai.targetModeWeight;
                                            if(k+p+1 < NUM_ROWS){
                                                if(pBoard.board[k+p+1][j] == 'H'){
                                                    ai.probabilityBoard[k+p-1][j] *= 2;
                                                }
                                            }
                                        }
                                    }
                                }else{
                                    ai.probabilityBoard[k+p][j]++;
                                }
                            }
                        }
                    }
                }

            }
        }

        // FIND SPOT WITH HIGHEST PROBABILITY
        for(int i = 0; i < NUM_ROWS; i++){
            for(int j = 0; j < NUM_COLS; j++){
                if(ai.probabilityBoard[i][j] > maxProb){
                    maxProb = ai.probabilityBoard[i][j];
                    r = i;
                    c = j;
                }
            }
        }

        // If the spot is a hit
        if(pBoard.board[r][c] == 's'){

            // Output hit
            cout << "Hit!!!" << endl;
            pBoard.board[r][c] = 'H';

            // LOOK FOR SHIP THAT WAS HIT. IF IT SUNK, GO TO HUNT MODE IF
            // THERE ARE NO MORE HITS THAT ARE NOT PART OF ALREADY SUNKEN
            // SHIPS, OTHERWISE REMAIN IN TARGET MODE BECAUSE THERE ARE
            // UNSUNKEN HITS

            // Temp variable for breaking out of loops
            bool foundShip = false;

            // Loop through enemy ships
            for(int i = 0; i < FLEET_SIZE; i++){

                // If the ship has not been sunk yet
                if(!ai.enemyShipSunk[i]){

                    // Loop through its points
                    for(int k = 0; k < pBoard.ships[i].points.size(); k++){

                        // If a point matches the shot
                        if(pBoard.ships[i].points[k].r == r &&
                                pBoard.ships[i].points[k].c == c){

                            // Increase the ship's hitcount
                            pBoard.ships[i].hitCount++;

                            // If it sunk
                            if(pBoard.ships[i].hitCount ==
                                    pBoard.ships[i].size){

                                // Tell the player
                                cout << "You sunk the "
                                     << pBoard.ships[i].name << "!!!"
                                     << endl;

                                // Tell the ai that the ship has sunk
                                ai.enemyShipSunk[i] = true;

                                // Assume there are no more active hits
                                // until proven otherwise
                                bool switchToHunt = true;

                                // Loop through enemy fleet
                                for(int j = 0; j < FLEET_SIZE; j++){

                                    // If ship not sunk
                                    if(!ai.enemyShipSunk[j]){

                                        // If there are any ships with a
                                        // hitcount of more than 0 and are
                                        // not sunken, there are still
                                        // active hits
                                        if(pBoard.ships[j].hitCount > 0){

                                            // Stay in target mode
                                            switchToHunt = false;
                                            break;
                                        }
                                    }
                                }

                                // Made it past checks, no more active hits
                                if(switchToHunt){

                                    // Switch to hunt mode
                                    ai.state = 1;
                                }
                            }
                            foundShip = true;
                            break;
                        }
                    }
                }
                if(foundShip){
                    break;
                }
            }
        }else{
            // AI missed :D
            cout << "You Missed." << endl;
            pBoard.board[r][c] = 'M';
        }
        break;
    }
}

/********************************************************************
 * takeTurn()
 *  Takes the turn for a human player
 ********************************************************************/
void takeTurn(PlayerBoard &pBoard){
    // VARIABLES
    char row; // Input variable for row
    int r, // Row number
        c; // column number

    do{

        // INPUT - receive row and column
        cout << "Fire a shot: ";
        cin >> row >> c;
        cout << endl;

        // Conver user input to row and column
        r = toupper(row) - 'A';
        c--;

        if(c != -1){ // If a char is inputted for c, there will be an error
            if(r < 0 || r >= NUM_ROWS || c < 0 || c >= NUM_COLS){

                // Numbers outside of board
                cout << "Invalid! Outside of board!" << endl;

                continue; // Receive new input

            }else if(pBoard.board[r][c] == 'H' || pBoard.board[r][c] == 'M'){

                // Space already shot at
                cout << "Invalid! Space already shot at!" << endl;

                continue; // Receive new input

            }
        } else{
            cin.clear();
        }
        break; // Made it through checks-> break out of loop
    }while(true);

    // If the shot is at a space with 's', it's a hit!
    if(pBoard.board[r][c] == 's'){
        // OUTPUT - HIT!!!
        cout << "Hit!!!" << endl;

        // Change space on board to 'H'
        pBoard.board[r][c] = 'H';

        // PROCESSING - find which ship was hit and increase hitcount

        bool foundShip = false; // Variable for breaking out of loop

        for(int i = 0; i < FLEET_SIZE; i++){ // Loop through the fleet

            // If the shit is still alive
            if(pBoard.ships[i].hitCount < pBoard.ships[i].size){

                // Loop through its points
                for(int k = 0; k < pBoard.ships[i].points.size(); k++){

                    // If a point matches the spot shot
                    if(pBoard.ships[i].points[k].r == r &&
                            pBoard.ships[i].points[k].c == c){

                        // Increment ship's hitcount
                        pBoard.ships[i].hitCount++;

                        // If the hit count equals the ship's size
                        if(pBoard.ships[i].hitCount ==
                                pBoard.ships[i].size){

                            // OUTPUT - The ship has been sunk
                            cout << "You sunk the "
                                 << pBoard.ships[i].name << "!!!" << endl;

                        }
                        // Ship has been found
                        foundShip = true;
                        break;
                    }
                }
            }

            // Ship has been found - break out of loop
            if(foundShip){
                break;
            }
        }

    }else{ // Not an 's', you missed :(
        cout << "You Missed." << endl;
        pBoard.board[r][c] = 'M'; // Set space to 'M'
    }
}

/********************************************************************
 * initBoard()
 *  Initializes the board for a human player and an ai
 ********************************************************************/
void initBoard(PlayerBoard &p1Board, AI &ai){
    // VARIABLES
    char emptyBoard[NUM_ROWS][NUM_COLS]; // An empty board

    // INITIALIZE
    // The empty board
    for(int i = 0; i < NUM_ROWS; i++){
        for(int k = 0; k < NUM_COLS; k++){
            emptyBoard[i][k] = ' ';
        }
    }

    // The two boards
    for(int k = 0; k < NUM_ROWS; k++){
        for(int j = 0; j < NUM_COLS; j++){
            p1Board.board[k][j] = ' ';
            ai.pBoard.board[k][j] = ' ';
        }
    }

    // PLAYER 1:
    cout << "Player 1 set your board." << endl;
    for(int i = 0; i < FLEET_SIZE; i++){ // Loop through ships
        displayBoards(p1Board.board, emptyBoard); // Display the board
        setShip(p1Board, i); // Set the ship
        cout << endl << endl;
    }

    // OUTPUT - display finished player 1 board
    displayBoards(p1Board.board, emptyBoard);

    // VARIABLES
    int r, c, o; // Row number, column number, orientation
    bool invalid; // Whether generated input is valid

    for(int i = 0; i < FLEET_SIZE; i++){ // Loop throuhg fleet
        int s = ai.pBoard.ships[i].size; // Temp variable for size of ship
        do{
            invalid = false; // Assume valid until proven otherwise

            o = rand() % 2; // Orientation either h or v

            if(o){ // Horizontal
                r = rand() % NUM_ROWS; // Random row
                c = rand() % s;        // Random column - size

                // Check to see if ship will overlap
                if(!spaceOccupied(r, c, 'h', ai.pBoard, i)){

                    // Ship will not overlap, set the ship
                    for(int k = 0; k < s; k++){ // Loop through size
                        ai.pBoard.board[r][c+k] = 's';
                        ai.pBoard.ships[i].points[k] = {r, c+k};
                    }

                }else{ // Will overlap
                    invalid = true;
                }

            }else{ // Vertical
                r = rand() % s;         // Random row - size
                c = rand() % NUM_COLS;  // Random column

                // Check to see if ship will overlap
                if(!spaceOccupied(r, c, 'v', ai.pBoard, i)){

                    // Ship will not overlap, set the ship
                    for(int k = 0; k < s; k++){ // Loop through size
                        ai.pBoard.board[r+k][c] = 's';
                        ai.pBoard.ships[i].points[k] = {r+k, c};
                    }

                }else{ // Will overlap
                    invalid = true;
                }
            }
        }while(invalid);
    }
}

/********************************************************************
 * initBoard()
 *  Initializes the board for two human players
 ********************************************************************/
void initBoard(PlayerBoard &p1Board, PlayerBoard &p2Board){
    // VARIABLES
    char emptyBoard[NUM_ROWS][NUM_COLS]; // Empty board

    // INITIALIZE - the empty board
    for(int i = 0; i < NUM_ROWS; i++){
        for(int k = 0; k < NUM_COLS; k++){
            emptyBoard[i][k] = ' ';
        }
    }

    // INITIALIZE - the two players' boards
    for(int k = 0; k < NUM_ROWS; k++){
        for(int j = 0; j < NUM_COLS; j++){
            p1Board.board[k][j] = ' ';
            p2Board.board[k][j] = ' ';
        }
    }

    // PLAYER 1's BOARD:
    cout << "Player 1 set your board." << endl;

    for(int i = 0; i < FLEET_SIZE; i++){ // Loop through fleet
        displayBoards(p1Board.board, emptyBoard); // Display board
        setShip(p1Board, i); // Set the ship
        cout << endl << endl;
    }
    // Display player 1's finished board
    displayBoards(p1Board.board, emptyBoard);

    cout << endl << endl;

    // PLAYER 2's BOARD:
    cout << "Player 2 set your board." << endl;

    for(int i = 0; i < FLEET_SIZE; i++){ // Loop through fleet
        displayBoards(p2Board.board, emptyBoard); // Display board
        setShip(p2Board, i); // Set the ship
        cout << endl << endl;
    }

    // Display player 2's finished board
    displayBoards(p2Board.board, emptyBoard);
}

/********************************************************************
 * spaceOccupied
 *  returns true or false depending on whether the ship will overlap
 *  with another already on the board
 ********************************************************************/
bool spaceOccupied(int r, int c, char orientation,
                   const PlayerBoard &pBoard, int shipIndex){

    // Loop through the ship's points
    for(int i = 0; i < pBoard.ships[shipIndex].size; i++){
        if(orientation == 'h'){ // Horizontal

            // If a space is not open, the ship will overlap
            if(pBoard.board[r][c+i] != ' '){
                return true;
            }

        }else { // Vertical

            // If a space is not open, the ship will overlap
            if(pBoard.board[r+i][c] != ' '){
                return true;
            }

        }
    }
    // Made it through checks, will not overlap
    return false;
}

/********************************************************************
 * setShip
 *  Sets a ship to the player board
 ********************************************************************/
void setShip(PlayerBoard &pBoard, int ship){
    // Variables
    int r, c; // Row and column numbers
    char orientation; // Orientation of ship

    // Receive valid info for ship
    getValidShipInfo(r, c, orientation, pBoard, ship);

    // Loop through the ship's points
    for(int i = 0; i < pBoard.ships[ship].size; i++){

        if(orientation == 'h'){ // Horizontal

            pBoard.board[r][c+i] = 's'; // Set char on board
            pBoard.ships[ship].points[i].r = r; // Set the point's r
            pBoard.ships[ship].points[i].c = c+i; // Set the point's c

        }else { // Vertical

            pBoard.board[r+i][c] = 's'; // Set char on board
            pBoard.ships[ship].points[i].r = r+i; // Set the point's r
            pBoard.ships[ship].points[i].c = c; // Set the point's c

        }

    }
}

/********************************************************************
 * getValidShipInfo
 *  Returns a valid row, column, and orientation to the reference
 *  arguments using a ship index and playerBoard
 ********************************************************************/
void getValidShipInfo(int &r, int &c, char &orientation,
                      const PlayerBoard &pBoard, int ship){

    // VARIABLES
    bool invalid; // Variable for valid input
    char row;     // The row char input
    do{
        invalid = false; // Assume valid until proven otherwise

        // INPUT - receive the row and column
        cout << "Enter the starting coordinates of your "
             << pBoard.ships[ship].name << ": ";
        cin >> row >> c;
        cout << endl;

        // Change row and column to row number and column number
        r = toupper(row) - 'A';
        c--;

        // Receive valid orientation input
        if(c != -1){ // If they entered a char for c, there will be an error
            do{

                // INPUT - receive orientation
                cout << "Enter the orientation of your "
                     << pBoard.ships[ship].name
                     << "(horizontal(h) or vertical(v)): ";
                cin >> orientation;
                cout << endl;

            }while(!(tolower(orientation) == 'h' ||
                     tolower(orientation) == 'v')); // Continue if not valid
        }else{
            cin.clear();
        }

        orientation = tolower(orientation);

        // If initial placement is outside of board
        if(c < 0 || r > NUM_ROWS || c > NUM_COLS || r < 0){
            invalid = true;
            cout << "Error: Ship placement is outside the board." << endl << endl;
            continue;
        }

        if(orientation == 'h'){ // Horizontal

            // If the ship will go out of board
            if(c + pBoard.ships[ship].size > NUM_ROWS){
                invalid = true;
                cout << "Error: Ship placement is outside the board."
                     << endl << endl;
                continue;
            }

        }else{ // Vertical

            // If the ship will go out of the board
            if(r + pBoard.ships[ship].size > NUM_COLS){
                invalid = true;
                cout << "Error: Ship placement is outside the board."
                     << endl << endl;
                continue;
            }

        }

        // Will not go outside of board, check if overlaps
        invalid = spaceOccupied(r, c, orientation, pBoard, ship);

        if(invalid){
            cout << "Error: Space already occupied." << endl << endl;
        }
    } while(invalid);
}

/********************************************************************
 * displayBoard
 *  Displays the two boards, the first being the one who's turn it
 *  is, and the second being the enemy's
 ********************************************************************/
void displayBoards(char p1[][10], char p2[][10]){
    // OUTPUT - Display the two boards

    cout << "                 YOUR BOARD                              "
            "             ENEMY BOARD" << endl;

    cout << "    ";

    // OUTPUT - the column numbers of player
    for(int i = 0; i < NUM_COLS; i++){
        cout << i+1 << "   ";
    }

    cout << SPACES << "  ";

    // OUTPUT - the column numbers of enemy
    for(int i = 0; i < NUM_COLS; i++){
        cout << i+1 << "   ";
    }
    cout << endl;

    cout << DASHES << SPACES << DASHES << endl;

    // OUTPUT - the rows
    for(int i = 0; i < NUM_ROWS; i++){

        // PLAYER:
        // Output the letter identifiers for each row
        cout << static_cast<char>('A' + i) << " |";

        // Output the player's board
        for(int k = 0; k < NUM_COLS; k++){
            cout << " " << p1[i][k] << " |";
        }

        cout << SPACES;

        // ENEMY:
        // Output the letter identifiers for each row
        cout << static_cast<char>('A' + i) << " |";

        // Output only the hits and misses of the enemy's board
        for(int k = 0; k < NUM_COLS; k++){
            cout << " "
                 << ((p2[i][k] == 'M' || p2[i][k] == 'H') ? p2[i][k] : ' ')
                 << " |";
        }
        cout << endl;
        cout << DASHES << SPACES << DASHES << endl;
    }
}

/********************************************************************
 * initFleet()
 *  Initializes the fleet of a playerboard
 ********************************************************************/
void initFleet(PlayerBoard &pBoard){
    // INTIALIZE - the ships' names and sizes
    pBoard.ships[0].name = "Carrier";
    pBoard.ships[0].size = CARRIER_SIZE;

    pBoard.ships[1].name = "Battleship";
    pBoard.ships[1].size = BATTLESHIP_SIZE;

    pBoard.ships[2].name = "Cruiser";
    pBoard.ships[2].size = CRUISER_SIZE;

    pBoard.ships[3].name = "Submarine";
    pBoard.ships[3].size = SUBMARINE_SIZE;

    pBoard.ships[4].name = "Destroyer";
    pBoard.ships[4].size = DESTROYER_SIZE;

    // INITIALIZE - The hitcounts and points
    for(int i = 0; i < FLEET_SIZE; i++){
        pBoard.ships[i].hitCount = 0;
        for(int k = 0; k < pBoard.ships[i].size; k++){
            Point temp = {0, 0};
            pBoard.ships[i].points.push_back(temp);
        }
    }
}

/********************************************************************
 * isGameOver()
 *  Returns true or false depending on whether the given playerboard
 *  has no more ships alive
 ********************************************************************/
bool isGameOver(const PlayerBoard &pBoard){
    for(int i = 0; i < FLEET_SIZE; i++){ // Loop through the fleet

        if(pBoard.ships[i].hitCount < pBoard.ships[i].size-1){
            return false; // There is at least 1 ship still alive
        }
    }
    return true; // No ships are alive, game over
}
