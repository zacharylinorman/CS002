/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : LAB 04
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/14/19
 ****************************************************************/
#include <iostream>
#include <string>

using namespace std;
/****************************************************************
 * Lab 04
 * ______________________________________________________________
 * This program contains 3 different exercises. Exercise 1 tells
 * the user whether their inputted word contains the characters
 * 'e' or 'x'. Exercise 2 transforms the user-inputted word, and
 * outputs the result. Exercise 3 tells the user where '.' and
 * "stop" is in their inputted sentence, or tells them that these
 * phrases are not present.
 * ______________________________________________________________
 * INPUT:
 *      ex       : The exercise number -> user input
 *      word     : The word used for exercise 1
 *                 and 2 -> user input
 *      sentence : The sentence used for exercise 3 -> user input
 *
 * OUTPUT:
 *      exercise 1: tells the user whether their inputted word
 *                  contains the characters 'e' or 'x'
 *      exercise 2: the transformed word with 'e' replaced with
 *                  '3', 'x' replaced with '*', and 'i' replaced
 *                  with '1'
 *      exercise 3: the index of '.' and "stop" in the user-
 *                  inputted sentence, or that they do not occur
 ****************************************************************/
int main()
{
    // VARIABLES
    int ex;          // INPUT - the exercise number
    string word,     // INPUT - the word used for exercise 1 and 2
           sentence; // INPUT - the sentence used for exercise 3

    // INPUT
    //receives exercise number
    cout << "Which exercise: ";
    cin >> ex;
    cout << endl;

    //if the exercise is 1 or 2, receive a word from the user
    if(ex == 1 || ex == 2){
        cout << "Enter a word: ";
        cin >> word;
        cout << endl;
    }else if(ex == 3){ // If the exercise is 3, receive a sentence
        cout << "Enter a sentence: ";
        cin >> sentence;
        cout << endl;
    }

    /* PROCESSING + OUTPUT- processes the input based on the exercise,
     *                      then outputs the result
     */
    if(ex == 1){
        // VARIABlES
        bool hasE, // CONTROL - true if word contains 'e'
             hasX; // CONTROL - true if word contains 'x'

        // PROCESSING - loop through the word to check for 'e' and 'x'
        hasE = hasX = false;
        for(int i = 0; i < word.size(); i++){
            if(word.at(i) == 'x'){
                hasX = true;
            }else if(word.at(i)){
                hasE = true;
            }
        }
        // OUTPUT - tells the user whether 'e' and 'x' were found
        if(hasE){
            cout << "Your word " << word << " contains the character 'e'"
                 << endl;
        }
        if(hasX){
            cout << "Your word " << word << " contains the character 'x'"
                 << endl;
        }

    }else if(ex == 2){
        // PROCESSING - loop through the word to replace the characters
        for(int i = 0; i < word.size(); i++){
            if(word.at(i) == 'e'){
                word.at(i) = '3';
            }else if(word.at(i) == 'x'){
                word.at(i) = '*';
            }else if(word.at(i) == 'i'){
                word.at(i) = '1';
            }
        }
        // OUTPUT - output the transformed word
        cout << "Your word transformed is " << word << endl;

    }else if(ex == 3){
        /* PROCESSING + OUTPUT - determines whether the sentence contains
         *                       '.' or "stop". If it does, output the
         *                       first occurence's index. If it does not,
         *                       tell the user that their sentence does
         *                       not contain the phrase.
         */

        if(sentence.find('.') != string::npos){
            cout << "The character '.' is located at index "
                 << sentence.find('.') << endl;
        }else{
            cout << "Your sentence does not contain the character '.'"
                 << endl;
        }


        if(sentence.find("stop") != string::npos){
            cout << "The word \"stop\" is located at index "
                 << sentence.find("stop") << endl;
        }else{
            cout << "Your sentence does not contain the word \"stop\""
                 << endl;
        }
    }


    return 0;
}
