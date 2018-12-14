#include <iostream>
#include <fstream>
#include <vector>
#include "Menu.hpp"
#include "Video.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int menuChoice = 0;
int genreChoice = 0;

bool importMovieDataFromFile();

int main()
{
    vector<Video> videoList;  //creates an empty vector of Videos called videoList


    //this bit of the program is going to get hairy while we figure
    //out how to read from the CSV, so I stuck it in its own function below
    if(!importMovieDataFromFile())  //read in data from CSV
        return 1;  //if the file can't be opened, immediately end the program;



    do {
        displayMainMenu();  //displays main menu and prompts user for input
        cin >> menuChoice;
        validateMenuChoice(menuChoice, MAINMENUMAX);  //ensures input is an integer and is in the menu

        if (menuChoice == 1)  //title search
        {
            //title search
        }
        else if (menuChoice == 2)  //genre search
        {
            displayGenreMenu();
            cin >> genreChoice;
            validateMenuChoice(genreChoice, GENREMENUMAX);  //ensures input is an integer and is in the menu

        }
        else if (menuChoice == 3)  //director search
        {
            //director search
        }
        else if (menuChoice == 4)  //check cart
        {
            //check cart
        }
        else if (menuChoice == 5)  //calculate total
        {
            //calculate total
        }

    } while (menuChoice != 6);  //Loop again if user did not select 6 to quit

    return 0;
}

bool importMovieDataFromFile()
{
    string title;
    Genre genre;
    string director;
    string actor;
    double price = 5.00;  //I arbitrarily set price = $5 for now
    
    std::ifstream inputFile("movie-dataset.csv");
    if (!inputFile)  // ifstream object equals 0 if open fails
    {
        cout << "Could not access file" << endl;
        return false;
    }

    while(inputFile) //read through to the end of the file
    {
        getline(inputFile,title,',');  //title = title from file
        getline(inputFile,genre,',');  //genre = genre from file
        //^I assume this error is because of the enum, it might be easier to change it to a string?

        getline(inputFile,director,',');  //director = director from file
        getline(inputFile,actor,'\n');  //director = director from file
        
        //price is constant so we don't change it here.

        //instantiate a new video with the above info and add to videoList
        videoList.push_back(Video(title, genre, director, actor, price)); 
        //^I'm not sure why it's undefined here, any ideas?
    }
        

    inputFile.close();
    return true;
}