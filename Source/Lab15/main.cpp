/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Lab 15
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 2/6/19
 ****************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/****************************************************************
 * Lab 15
 * ______________________________________________________________
 * This program prints the titles, directors, year released, and
 * running times for 12 different movies. The first movie is hard
 * coded in, the second comes from user input, and the rest come
 * from an input file.
 * ______________________________________________________________
 * INPUT:
 *      md2     : The title, director, year released, and running
 *                time
 *
 * OUTPUT:
 *      md      : The data of all 12 movies are outputted
 *
 ****************************************************************/

// STRUCTURES

struct MovieData{ // This structure stores movie data
    string title,       // The title of the movie
           director;    // The director of the movie
    int yearReleased,   // The year the movie was released
        runningTime;    // How long the move runs in minutes
};

// PROTOTYPES
/****************************************************************
 * printMovieData
 *  This function prints the data of a given MovieData structure
 ****************************************************************/
void printMovieData(const MovieData &m);// The MovieData to print

// GLOBAL VARIALBES
const int SIZE = 12; // The size of the array of MovieData

int main()
{

    // VARIABLES
    MovieData md1 = {"Apollo 13", "Ron Howard", 1995, 140}; // Movie 1
    MovieData md2; // Movie 2
    MovieData md[SIZE]; // The array of movies

    ifstream inFile; // The input stream

    // INPUT - receive data for movie 2
    cout << "Enter Title: ";
    getline(cin, md2.title);
    cout << endl;

    cout << "Enter Director: ";
    getline(cin, md2.director);
    cout << endl;

    cout << "Enter Year Released: ";
    cin >> md2.yearReleased;
    cout << endl;

    cout << "Enter Running Time (in minutes): ";
    cin >> md2.runningTime;
    cout << endl;

    // PROCESSING - set the first two movies in the array
    md[0] = md1;
    md[1] = md2;

    // PROCESSING - receive the other 10 moives from the file
    inFile.open("movies.txt");
    if(inFile){
        for(int i = 2; i < SIZE; i++){ // Loop through the rest of array
            getline(inFile, md[i].title);
            getline(inFile, md[i].director);
            inFile >> md[i].yearReleased;
            inFile >> md[i].runningTime;
            inFile.get(); // Get through \n for next getline
            inFile.get(); // Get through empty line for next getline
        }
    }else {
        cout << "Cannot open file" << endl;
    }
    inFile.close();

    // OUTPUT - loop through movie array to print data using function
    for(int i = 0; i < SIZE; i++){
        printMovieData(md[i]);
        cout << endl;
    }


    return 0;
}

/****************************************************************
 * printMovieData
 *  This function prints the data of a given MovieData structure
 ****************************************************************/
void printMovieData(const MovieData &m){
    // OUTPUT - print the movie data
    cout << "Title: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Year released: " << m.yearReleased << endl;
    cout << "Running Time: " << m.runningTime << endl;
}
