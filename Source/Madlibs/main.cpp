/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Madlibs
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/9/19
 ****************************************************************/

#include <iostream>
#include <string>

using namespace std;

/****************************************************************
 * MADLIBS
 * ______________________________________________________________
 * This program accepts 10 inputs in from a user, then outputs a
 * story using the inputs.
 * ______________________________________________________________
 * INPUT:
 *      adjective   : First adjective -> input from user
 *      noun        : First noun -> input from user
 *      name        : Name -> input from user
 *      age         : Age -> input from user
 *      emotion     : First emotion -> input from user
 *      verbing     : First verb endng with -ing -> input from user
 *      emotion2    : Second emotion -> input from user
 *      verbing2    : Second verb ending with -ing -> input from user
 *      adjective2  : Second adjective -> input from user
 *      noun2       : Second noun -> input from user
 *
 * OUTPUT:
 *      A short story using the user inputs. Preceded and followed by the
 *      measuring stick constant.
 *
 *      measuringStick  : A string containing 80 '-'
 *      Story           :
 *        Once upon a time, there was a *adjective* *noun* named *name*.
 *        *name* was *age* years old. *name* was a very *emotion* *noun*.
 *        One day, *name* was *verb-ing*. Although *name* is usually a very
 *        *emotion* *noun*, *name* was actually feeling very *emotion2*
 *        while *verbing*. This was very strange. The next day, *name*
 *        decided to go *verbing2*. While *verbing2*, *name* saw a
 *        *adjective2* *noun2* doing the same. Because of this, *name*
 *        decided to go *verbing2* every day for the rest of its existence.
 ****************************************************************/

int main()
{
    // Constants
    string measuringStick(80, '-'); //OUTPUT - A string containing 80 '-'

    // Variables *** Should I declare each variable separately instead? ***
    string adjective,       // INPUT - First adjective
            noun,           // INPUT - First noun
            name,           // INPUT - Name
            age,            // INPUT - Age
            emotion,        // INPUT - First emotion
            verbing,        // INPUT - First verb ending with -ing
            emotion2,       // INPUT - Secon emotion
            verbing2,       // INPUT - Second verb ending with -ing
            adjective2,     // INPUT - Second adjective
            noun2;          // INPUT - Second noun

    cout << "************************************************************"
            "****" << endl;
    cout << "  AUTHOR        : Zachary Norman" << endl;
    cout << "  ASSIGNMENT    : Madlibs" << endl;
    cout << "  CLASS         : CS02" << endl;
    cout << "  SECTION       : MTWH: 7:30-12:30" << endl;
    cout << "  DUE DATE      : 1/9/19" << endl;
    cout << "************************************************************"
            "****" << endl;


    // INPUT - Receiving user input for variables.
    cout << "Please enter an adjective: ";
    cin >> adjective;
    cout << "Your input: " << adjective << endl << endl;

    cout << "Please enter a noun: ";
    cin >> noun;
    cout << "Your input: " << noun << endl << endl;

    cout << "Please enter a name: ";
    cin >> name;
    cout << "Your input: " << name << endl << endl;

    cout << "Please enter an age: ";
    cin >> age;
    cout << "Your input: " << age << endl << endl;

    cout << "Please enter an emotion: ";
    cin >> emotion;
    cout << "Your input: " << emotion << endl << endl;

    cout << "Please enter a verb ending with -ing: ";
    cin >> verbing;
    cout << "Your input: " << verbing << endl << endl;

    cout << "Please enter another emotion: ";
    cin >> emotion2;
    cout << "Your input: " << emotion2 << endl << endl;

    cout << "Please enter another verb ending with -ing: ";
    cin >> verbing2;
    cout << "Your input: " << verbing2 << endl << endl;

    cout << "Please enter another adjective: ";
    cin >> adjective2;
    cout << "Your input: " << adjective2 << endl << endl;

    cout << "Please enter another noun: ";
    cin >> noun2;
    cout << "Your input: " << noun2 << endl << endl;


    /* PROCESSING & OUTPUT - Printing out story w/ measuring sticks using
     *                       the user-inputted variables.
     */
    cout << measuringStick << endl;

    cout << "Once upon a time, there was a " << adjective << " " << noun
            << " named " << name << ". "
         << name << endl << "was " << age << " years old. "
         << name << " was a very " << emotion << " " << noun << ". "

         << endl << endl

         << "One day, " << name << " was " << verbing << ". "
         << "Although " << name << " is usually a very " << endl << emotion
            << " " << noun << ", " << name << " was actually feeling very "
            << emotion2 << " while " << endl << verbing << ". "
         << "This was very strange."

         << endl << endl

         << "The next day, " << name << " decided to go " << verbing2
            << ". "
         << "While " << verbing2 << ", " << name << endl << "saw a "
            << adjective2 << " " << noun2 << " doing the same. "
         << "Because of this, " << name << " decided" << endl << "to go "
            << verbing2 << " every day for the rest of its existence."

         << endl;

    cout << measuringStick << endl;

    return 0;
}
