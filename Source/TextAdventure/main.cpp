/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Text Adventure
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/27/19
 ****************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/****************************************************************
 * Text Adventure
 * ______________________________________________________________
 * This program is a simple text adventure game. Every room in
 * the game has 4 doors for the player to choose from, each
 * associated with an uppercase direction: N, E, S or W. Three of
 * the doors open up to another room, and the 4th door is an exit
 * from the game. Of the three non-exit doors, one will send the
 * player to a room containing a monster. Another will send the
 * player to a room containing a genie. The third non-exit door
 * will send the player to a room that has a picture. When the
 * player exits, their score is the sum of their bananas and
 * oranges.
 * ______________________________________________________________
 * INPUT:
 *      name        : The player's name
 *      monsterName : The name of the monster
 *      door        : The selected door
 *
 * OUTPUT:
 *      The output differs based on which door is chosen.
 *      Description of each door is shown at their respective
 *      function descriptions.
 *
 ****************************************************************/


// PROTOTYPES

/****************************************************************
 * monsterRoom(int&, int&, string)
 *  This function returns nothing; takes two integers both by
 *  reference and a string by value. The function reduces the
 *  values of the variables storing the number of bananas and
 *  oranges to 0. This function also tells the player what
 *  monster attacked them.
 ****************************************************************/
void monsterRoom(int&,      // Number of bananas
                 int&,      // Number of oranges
                 string);   // Monster name


/****************************************************************
 * genieRoom(int&, int&)
 *  This function returns nothing; takes two integers both by
 *  reference (number of bananas and oranges, respectively).
 *  Increases the values of the variables storing the number of
 *  bananas and oranges by the appropriate number as per the game
 *  specification (2 bananas, 1 orange). The function also
 *  outputs the message telling the player what she encountered
 *  in the room and what happened.
 ****************************************************************/
void genieRoom(int&,        // Number of bananas
               int&);       // Number of oranges


/****************************************************************
 * pictureRoom()
 *  This fucntion takes no parameters and returns nothing. This
 *  function outputs the proper announcement and draws a picture
 *  to the screen using drawPicture()
 ****************************************************************/
void pictureRoom();

/****************************************************************
 * drawPicture()
 *  This function draws a picture.
 ****************************************************************/
void drawPicture();

int main()
{
    // VARIABLES
    int bananas,        // Number of bananas
        oranges;        // Number of oranges
    string name,        // Name of player
           monsterName; // Name of monster
    bool finished;      // Has the player exited?

    char door;          // The inputted door

    // INITIALIZE VARIABLES
    bananas = 5, oranges = 3;
    finished = false;

    // INPUT - receive name and monster name
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl;

    cout << "Name your scariest monster: ";
    cin >> monsterName;
    cout << endl;

    srand(500); // Set seed for random numbers to 500
    while(!finished){ // As long as the player has not exited

        // OUTPUT - output game state
        cout << name << ", you are in a room with 4 doors." << endl
             << endl;
        cout << "You are carrying " << bananas << " bananas and "
             << oranges << " oranges." << endl;

        // INPUT - receive player choice of door
        do{ // Continue until receive valid input
            cout << "Pick a door to enter by typing the direction it is "
                    "in (N/E/S/W): ";
            cin >> door;
            cout << endl;
        }while(!(door == 'N' ||
                 door == 'E' ||
                 door == 'S' ||
                 door == 'W'));
        cout << endl;

        // ALIGNMENTS ARE SWAPPED FOR HYPER GRADE
        /* PROCESSING & OUTPUT - Generate random alignment and call
         *                       appropriate function
         */
        if(!(rand()%2)){ // Doors have 2 sets of random alignments
            // Alignment 1
            if(door == 'N'){ // NORTH
                monsterRoom(bananas, oranges, monsterName);
            }else if(door == 'S'){ // SOUTH
                genieRoom(bananas, oranges);
            }else if(door == 'E'){ // EAST
                pictureRoom();
            }else if(door == 'W'){ // WEST
                finished = true; // Player has exited!!
            }
        }else {
            // Alignment 0
            if(door == 'N'){ // NORTH
                finished = true; // Player has exited!!
            }else if(door == 'S'){ // SOUTH
                monsterRoom(bananas, oranges, monsterName);
            }else if(door == 'E'){ // EA    ST
                genieRoom(bananas, oranges);
            }else if(door == 'W'){ // WEST
                pictureRoom();
            }
        }
    }

    // OUTPUT - Player has exited!! Calculate and output score
    cout << "You found the exit!" << endl;
    cout << "Your score is " << (bananas + oranges) << "(" << bananas
         << " bananas and " << oranges << " oranges)." << endl;
    cout << "Bye bye!!!" << endl;

    return 0;
}


void monsterRoom(int& bananas, int& oranges, string monsterName){
    // PROCESSING - Set bananas and oranges to 0
    bananas = 0;
    oranges = 0;

    // OUTPUT - tell the user using monster name
    cout << "WATCH OUT!!!" << endl;
    cout << monsterName << " attacks you and steals all of your bananas "
                           "and oranges." << endl;
}


void genieRoom(int& bananas, int& oranges){
    // PROCESSING - Add the amount of bananas and oranges
    bananas += 2;
    oranges += 1;

    // OUTPUT - tell the user
    cout << "!!Poof!! ";
    cout << "A Genie pops out and grants you 2 bananas and 1 orange."
         << endl;
}

void pictureRoom(){
    // OUTPUT - tell player they found picture and draw it
    cout << "You found a picture!" << endl;
    drawPicture();
}

void drawPicture()
{
    // OUTPUT - draw the picture

    cout << "        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|" << endl;
    cout << "     |[][][][][][]|" << endl;
    cout << "   __| __         |__" << endl;
    cout << "  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)" << endl;
    cout << "  |  |[] []  ==   |  |" << endl;
    cout << "  |  |____________|  |" << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ " << endl;
    cout << endl;
}
