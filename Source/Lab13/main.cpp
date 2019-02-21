/****************************************************************
 * AUTHOR        : Zachary Norman & Timothy Pieschala
 * ASSIGNMENT    : Lab 13
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/31/19
 ****************************************************************/
#include <iostream>
#include <string>

using namespace std;
/****************************************************************
 * Lab 13
 * ______________________________________________________________
 * This program has two exercises. The first one receives an
 * input from a user of a sentence with no spaces with words
 * separated by capital letters. It outputs the sentence with
 * only the first word capitalized with spaces between words. The
 * second exercise receives three sentences from the user. It
 * outputs the the first sentence with all occurences of the
 * second sentence replaced with the third sentence.
 * ______________________________________________________________
 * INPUT:
 *      ex          : The exercise number
 *      sentence    : The first sentence
 *      sentence2   : The second sentence
 *      sentence3   : The third sentence
 * OUTPUT:
 *      Exercises
 *          1       : The string with spaces and capitalization
 *          2       : The first sentence with all occurences of
 *                    the second sentence replaced with the third
 ****************************************************************/

// PROTOTYPES
/****************************************************************
 * replaceSubstring()
 *  This function returns string1 with all occurences of string2
 *  replaced with string3
 ****************************************************************/
string replaceSubstring(string string1, // The main string
                        string string2, // The string to be replaced
                        string string3);// The string replacing string2

int main()
{
    // INPUT - Receive exercise number
    int ex;
    cout << "Which exercise?";
    cin >> ex;
    cout << endl << endl;

    cin.get(); // So that the next getline() will work

    // PROCESSING - exercises
    if(ex == 1){ // Exercise 1
        // VARIABLES
        string sentence;    // The sentence to modify

        // INPUT - receive sentence
        cout << "Enter a sentence (no spaces, 1st letter of each word "
                "isuppercase): " << endl;
        getline(cin, sentence);
        cout << endl;

        // PROCESSING - Go through the sentence to modify
        for(int i = 1; i < sentence.size(); i++){
            if(isupper(sentence.at(i))){ // If an uppercase letter
                sentence.at(i) = tolower(sentence.at(i));
                sentence.insert(i, " "); // Add a space
                i++; // Added a space so increment i
            }
        }

        // OUTPUT - the modified sentence
        cout << sentence << endl << endl;


    }else if(ex == 2){// Exercise 2

        // VARIABLES
        string sentence;    // The main sentence
        string sentence2;   // The sentence to replace
        string sentence3;   // The sentence to replace sentence2

        // INPUT - receive the sentences
        cout << "Enter the main string: " << endl;
        getline(cin, sentence);

        cout << "Enter the string to replace: " << endl;
        getline(cin, sentence2);

        cout << "Enter the replacement string: " << endl;
        getline(cin, sentence3);

        // PROCSESING & OUTPUT - Use replace substring and output result
        cout << replaceSubstring(sentence, sentence2, sentence3) << endl;
        cout << endl;
    }
    return 0;
}

/****************************************************************
 * replaceSubstring()
 *  This function returns string1 with all occurences of string2
 *  replaced with string3
 ****************************************************************/
string replaceSubstring(string string1, string string2, string string3){
    // Loop through main string
    for(int i = 0 ; i < string1.size(); i++){
        if(string1.find(string2, i) == i){// If string2 is found at i
            string1.replace(i, string2.size(), string3);// Replace with s3
            i += string3.size();    // Add the size of s3 to i to continue
        }
    }
    // Return the modified string1
    return string1;

}
