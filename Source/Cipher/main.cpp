/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Cipher
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/20/19
 ****************************************************************/
#include <iostream>
#include <string>

using namespace std;
/****************************************************************
 * Cipher
 * ______________________________________________________________
 * This program either encrypts or decrypts a user's word using a
 * translation map of the user's choice. It will give errors for
 * invalid inputs.
 * ______________________________________________________________
 * INPUT:
 *      method      : Either encryption or decryption
 *      map         : The translation map
 *      word        : The word to translate
 *
 * OUTPUT:
 *      Errors:
 *          - Invalid method choice
 *          - Invalid translation map size
 *          - Encryption cannot be performed
 *          - Decryption cannot be performed
 *      Encryption:
 *          Outputs the encrypted word or an error
 *      Decryption:
 *          Outputs the decrypted word or an error
 ****************************************************************/
int main()
{
    // CONSTANTS
    string defaultMap = "zyxwvutsrqponmlkjihgfedcba"; // default map

    // VARIABLES
    string method,  // INPUT - The method of translation
           map,     // INPUT - The translation map
           word;    // INPUT - The word to translate

    // INPUT - Receiving the method of translation
    cout << "What is the method (encryption or decryption)? ";
    cin >> method;
    cout << endl;

    // PROCESSING & OUTPUT - Validates user's choice of method
    if(!(method == "encryption" || method == "decryption")){
        cout << "Error: invalid method choice." << endl;
        return 0;
    }

    // INPUT - Receiving the translation map
    cout << "What is the translation map (type 'default' to use "
            "default): ";
    cin >> map;
    cout << endl;

    // PROCESSING & OUTPUT - Validates user's choice of method
    if(map == "default"){ // If "default", use the default map
        map = defaultMap;
    }else if(map.size() != 26){
        cout << "Error: invalid translation map size." << endl;
        return 0;
    }

    // INPUT - Receving the word to be translated
    cout << "What is the single word to translate: ";
    cin >> word;
    cout << endl;

    if(method == "encryption"){
        // ENCRYPTION

        /* PROCESSING & OUTPUT - loops through the characters of the word.
         *                       If the word contains a character out of
         *                       range, output an error. Translate the
         *                       character to the one in the map of the
         *                       same alphabetical position.
         */
        for(int i = 0; i < word.size(); i++){ // LOOP THOUGH WORD

            if(word.at(i)<'a'||word.at(i)>'z'){ // WORD VALIDATION
                cout << "Error: encryption cannot be performed." << endl;
                return 0;
            }
            /* PROCESSING - Translate character to the one in the map of
             *              the same alphabetical position
             */
            word.at(i) = map.at(static_cast<int>(word.at(i)-'a'));
        }

        // OUTPUT - The successfully encrypted word
        cout << "Encrypted word: " << word << endl;
    }else if(method == "decryption"){
        // DECRYPTION

        /* PROCESSING & OUTPUT - loops through the characters of the word.
         *                       loops through the map at each character of
         *                       the word. If the word's character matches
         *                       the map's character, set the word's
         *                       character to the alphibetical position
         *                       of the index of the character in the map.
         *                       If the end of the map is reached, and a
         *                       match is not found, output an error.
         *
         */
        for(int i = 0; i < word.size(); i++){ // LOOP THROUGH WORD

            for(int k = 0; k < map.size(); k++){ // LOOP THROUGH MAP
                if(word.at(i) == map.at(k)){ // Check if character is found
                    word.at(i) = k+'a'; // Decrypt
                    break; // Break out of map to go to next character
                }
                if(k == map.size()-1){ // Reached the end of map: error
                    cout << "Error: decryption cannot "
                            "be performed." << endl;
                    return 0;
                }
            }
        }

        // OUTPUT - The sucessfully decrypted word
        cout << "Decrypted word: " << word << endl;
    }
    return 0;
}
