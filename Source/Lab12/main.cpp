/****************************************************************
 * AUTHOR        : Zachary Norman & Timothy Pieschala
 * ASSIGNMENT    : Lab 12
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/30/19
 ****************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

/****************************************************************
 * Lab 12
 * ______________________________________________________________
 * This program accepts a line up to 100 characters from the user
 * and gives the user a menu of options to perform on their line.
 * ______________________________________________________________
 * INPUT:
 *      cString[]   : The string to manipulate
 *      input       : The menu choice
 * OUTPUT:
 *      Menu Options:
 *          a       : Ouputs the number of vowels
 *          b       : Ouputs the number of consonants
 *          c       : Changes string to uppercase - no output
 *          d       : Changes string to lowercase - no output
 *          e       : Displays the string
 *          f       : Allows user to enter new string
 *          m       : Displays menu
 ****************************************************************/

// PROTOTYPES
/****************************************************************
 * numVowels()
 *  This function takes a cstring and returns the number
 *  of vowels
 ****************************************************************/
int numVowels(const char cString[]); // The user's cstring

/****************************************************************
 * numConsonants()
 *  This function takes a cstring and returns the number
 *  of consonants
 ****************************************************************/
int numConsonants(const char cString[]); // The user's cstring

/****************************************************************
 * stringToUpper()
 *  This function takes a cstring and returns, by reference,
 *  the cstring with all uppercase characters
 ****************************************************************/
void stringToUpper(char cString[]); // The user's cstring

/****************************************************************
 * stringToLower()
 *  This function takes a cstring and returns, by reference,
 *  the cstring with all lowercase characters
 ****************************************************************/
void stringToLower(char cString[]); // The user's cstring

/****************************************************************
 * displayMenu()
 *  This function outputs the menu options
 ****************************************************************/
void displayMenu();

int main()
{
    // VARIABLES
    char cString[100];  // The user's line to manipulate
    char input;         // The user's menu choice


    // INPUT - Receive the user's line to manipulate
    cout << "Input a line of text, up to 100 characters: ";
    cin.getline(cString, 100);
    cout << endl;

    // OUTPUT - Display the menu with displayMenu()
    displayMenu();

    // PROCESSING & OUTPUT - Receive menu option and output appropriately
    do{
        // INPUT - Receive menu choice
        cout << "Enter your menu selection: ";
        cin >> input;
        cout << endl;

        input = toupper(input); // Change input to uppercase

        // Menu choices
        if(input == 'A'){ // Display number of vowels
            cout << "Number of vowels: " << numVowels(cString) << endl
                 << endl;
        }else if(input == 'B'){ // Display number of consonants
            cout << "Number of consonants: " << numConsonants(cString)
                 << endl << endl;
        }else if(input == 'C'){ // Change the cstring to all uppercase
            stringToUpper(cString);
        }else if(input == 'D'){ // Change the cstring to all lowercase
            stringToLower(cString);
        }else if(input == 'E'){ // Display the cstring
            cout << cString << endl << endl;
        }else if(input == 'F'){ // Allow the user to enter new line
            cin.get(); // Allows for another getline()
            // Receive new cstring line
            cout << "Input a new line of text, up to 100 characters: ";
            cin.getline(cString, 100);
            cout << endl;
        }else if(input == 'M'){ // Display menu
            displayMenu();
        }
    }while(input != 'X');

    return 0;
}
/****************************************************************
 * displayMenu()
 *  This function outputs the menu options
 ****************************************************************/
void displayMenu(){
    // OUTPUT - Display the menu
    cout << "A)  Count the number of vowels in the string" << endl
         << "B)  Count the number of consonants in the string" << endl
         << "C)  Convert the string to uppercase" << endl
         << "D)  Convert the string to lowercase" << endl
         << "E)  Display the current string" << endl
         << "F)  Enter another string" << endl
         << endl
         << "M)  Display this menu" << endl
         << "X)  Exit the program" << endl;
    cout << endl;
}

/****************************************************************
 * numVowels()
 *  This function takes a cstring and returns the number
 *  of vowels
 ****************************************************************/
int numVowels(const char cString[]){
    // VARIABLES
    int val = 0; // Number of vowels in cString

    // PROCESSING - Loop through cstring to count vowels
    for(int i = 0; i < strlen(cString) - 1; i++){ // Loop through cString
        char temp = tolower(cString[i]); // Current character
        if(temp == 'a' ||   // If the character is a basic vowel
           temp == 'i' ||
           temp == 'o' ||
           temp == 'e' ||
           temp == 'u'){
            val++;          // Increment number of vowels
        }
    }
    return val;             // Return number of vowels
}

/****************************************************************
 * numConsonants()
 *  This function takes a cstring and returns the number
 *  of consonants
 ****************************************************************/
int numConsonants(const char cString[]){
    // VARIABLES
    int val = 0; // Number of consonants in cString

    // PROCESSING - Loop through cstring to count consonants
    for(int i = 0; i < strlen(cString) - 1; i++){ // Loop through cString
        char temp = tolower(cString[i]); // Current character
        if(!(temp == 'a' ||     // As long as not a basic vowel
             temp == 'i' ||
             temp == 'o' ||
             temp == 'e' ||
             temp == 'u') && isalpha(temp)){ // And is part of the alphabet
            val++;  // Increment number of consonants
        }
    }
    return val;     // Return number of consonants
}

/****************************************************************
 * stringToUpper()
 *  This function takes a cstring and returns, by reference,
 *  the cstring with all uppercase characters
 ****************************************************************/
void stringToUpper(char cString[]){
    // PROCESSING - loop through cstring and set each chat to uppercase
    for(int i = 0; i < strlen(cString) - 1; i++){
        cString[i] = toupper(cString[i]);
    }
}

/****************************************************************
 * stringToLower()
 *  This function takes a cstring and returns, by reference,
 *  the cstring with all lowercase characters
 ****************************************************************/
void stringToLower(char cString[]){
    // PROCESSING - loop through cstring and set each chat to uppercase
    for(int i = 0; i < strlen(cString) - 1; i++){
        cString[i] = tolower(cString[i]);
    }
}
