/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Breakfast Billing System
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 2/8/19
 ****************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/****************************************************************
 * Breakfast Billing System
 * ______________________________________________________________
 * This program prints out a given menu and allows the user to
 * order items from it. It thens outputs the bill including a 5%
 * tax.
 * ______________________________________________________________
 * INPUT:
 *      filename        : The filename of hte menu
 *      itemNum         : The item's number
 *      numItems        : The number of items to order
 *
 * OUTPUT:
 *      showMenu()      : Prints the menu
 *      printCheck()    : Prints the check
 *
 ****************************************************************/

// STRUCTURES
struct MenuItemType{    // A menu item
    string menuItem;    // The name of the item
    double menuPrice;   // The price of the item
};

// PROTOYPES
/****************************************************************
 * getData
 *  This function receives a filename from the user and generates
 *  a vector of MenuItemTypes to return
 ****************************************************************/
vector<MenuItemType> getData();

/****************************************************************
 * showMenu
 *  This function receives a vector of menu items to print
 ****************************************************************/
void showMenu(const vector<MenuItemType> &menu); // The menu to print


/****************************************************************
 * printCheck
 *  This function receives an array of orders and a vector of
 *  menu items to calculate and print the check
 ****************************************************************/
void printCheck(int orders[], // The number of orders
                const vector<MenuItemType> &menu); // The menu

int main()
{
    // VARIABLES
    vector<MenuItemType> menuList = getData(); // The menu- use getData to
                                               // receive from user
    int orders[menuList.size()]; // The list of orders
    int itemNum,    // The item number
        numItems;   // The number of items

    // INITIALIZE - initialize the list of orders to 0 of each item
    for(int i = 0; i < menuList.size(); i++){
        orders[i] = 0;
    }

    // OUTPUT - set the precision for ouputting the money amounts
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    do{ // Loop as long as the user does not enter 0

        // OUTPUT - show the menu
        showMenu(menuList);

        // INPUT - receive a valid menu choice from user
        do{
            cout << "Enter the item number: ";
            cin >> itemNum;
            cout << endl;
        }while(itemNum < 0 || itemNum >> menuList.size());

        // Input - receive the number of items to order
        if(itemNum != 0){ // The user does not want to exit yet
            cout << "How many would you like to order? ";
            cin >> numItems;
            cout << endl;
            cout << endl << endl;
            orders[itemNum-1] = numItems; // Add to order array
        }
    }while(itemNum != 0);

    // OUTPUT - print the check when the user is done
    cout << endl << endl;
    printCheck(orders, menuList);
    return 0;
}

/****************************************************************
 * getData
 *  This function receives a filename from the user and generates
 *  a vector of MenuItemTypes to return
 ****************************************************************/
vector<MenuItemType> getData(){
    // VARIABLES
    vector<MenuItemType> menu; // The vector to return
    ifstream inFile;    // The input stream
    string filename;    // The filename

    // INPUT - receive the filename
    cout << "Enter filename: ";
    cin >> filename;
    cout << endl << endl;

    // PROCESSING - open and parse menu
    inFile.open(filename.c_str()); // Open the file
    if(inFile){
        string menuItem;    // Temp variable for each line
        while(getline(inFile, menuItem)){
            // Create a new MenuItemType and parse the line of text
            MenuItemType temp = {menuItem.substr(0, menuItem.find("$")),
                                 atof(menuItem.substr(menuItem.find("$")+1,
                                 menuItem.size()).c_str())};
            menu.push_back(temp); // Add the menu item to the vector
        }
    }
    inFile.close(); // Close the file
    return menu; // Return the vector
}

/****************************************************************
 * showMenu
 *  This function receives a vector of menu items to print
 ****************************************************************/
void showMenu(const vector<MenuItemType> &menu){
    // OUTPUT - Show the menu
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << endl;
    cout << "             Menu" << endl;
    cout << endl;
    for(int i = 0; i < menu.size(); i++){ // Loop through the menu
        // Format the contents of the vector
        cout << i+1 << ". ";
        cout << setw(20) << left << menu[i].menuItem;
        cout << "$";
        cout << setw(5) << right << menu[i].menuPrice << endl;
    }

    // Let the user know to enter 0 when they are finished
    cout << endl;
    cout << "Enter 0 when you finish your order." << endl;
    cout << endl;
}

/****************************************************************
 * printCheck
 *  This function receives an array of orders and a vector of
 *  menu items to calculate and print the check
 ****************************************************************/
void printCheck(int orders[], const vector<MenuItemType> &menu){
    // VARIABLES
    double total;   // The total cost w/o tax
    MenuItemType tempMenuItem; // Temparay variable for menu item
    int numItems;   // The number of items
    double price;   // The price of each item

    // INTITIALIZE
    total = 0;

    // OUTPUT - print the check
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << endl;
    cout << "             SALE" << endl;
    cout << endl;
    // PROCESSING - calculate the cost of orders
    for(int i = 0; i < menu.size(); i++){
        if(orders[i] != 0){
            // Set the variables
            tempMenuItem = menu[i];
            numItems = orders[i];
            price = numItems *  tempMenuItem.menuPrice;
            total += price; // Add price to total

            // Format and output
            cout << setw(3) << left  << numItems;
            cout << setw(20) << tempMenuItem.menuItem;
            cout << "$";
            cout << setw(5) << right << price << endl;
        }
    }
    // OUTPUT - Print tax
    cout << setw(23) << left << "Tax";
    cout << "$";
    cout << setw(5) << right << total * 0.05 << endl;
    cout << "-----------------------------" << endl;

    // OUTPUT - Print total amount with tax
    cout << setw(23) << left << "Amount Due";
    cout << "$";
    cout << setw(5) << right << total * 1.05 << endl << endl;
}
