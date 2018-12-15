/*
This file contains the functions used in the BawkBuster submission
at the BeaverHacks Winter 2018 Hackathon.
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Video.hpp"
#include "Cart.hpp"

/****************************************************************************************
Video Vector Functions
****************************************************************************************/

/*
takes a vector of viedos by reference, fills with movie info from file
*/

bool importMovieDataFromFile(std::vector<Video> &videoList);

/*
mainMenu()
Main function that manages the user's access to submenus.
Allows user to select a submenu choice.
*/

//<<<<<<< HEAD
void mainMenu(std::vector<Video> &videoList);
//=======
/****************************************************************************************
Clear Screen Function For Linux and Windows OS's
****************************************************************************************/
/*
clear_screen()
Function to remove all text from the console screen
that functions with Windows and Linux operating systems.
*/

void clear_screen();

/****************************************************************************************
Main Menu Functions
****************************************************************************************/

/*
mainMenu()
Main function that manages the user's access to submenus.
Allows user to select a submenu choice.
*/

//void mainMenu();
//>>>>>>> 181aa59ef2cb18438b716074538fb96da6ed3301

/*
displayMainMenu()
Displays the main menu choices for the user to choose from
*/

void displayMainMenu();

/*
validateMainMenuChoice(int &choice)
Validates the user's input for the main menu options.
If the user's input is not an integer, or the input
integer is out of bounds (larger than 6 or smaller than 1), 
the while loop will activate and prompt the user to reenter their choice.
*/

void validateMainMenuChoice(int &choiceMain);

/*
void mainMenuSwitch(int choiceMain)
Uses user input to direct to desired sub menu.
*/

void mainMenuSwitch(int choiceMain, std::vector<Video> &videoList);

/****************************************************************************************
Title Search Submenu Functions
****************************************************************************************/

/*
titleSearchMain()
Main function that executes when user selects option 1 in main menu.
Allows user to search movies by title.
Allows user to add movies found in search to cart.
Returns user to main menu when user is done searching by title.
*/

void titleSearchMain(std::vector<Video>& videoList);

/*
titleSearchVector()
takes a const vector of movies to search, a vector of videos to add results to, and a search term.
*/

void titleSearchVector(const std::vector<Video>& videos, std::vector<Video>& results, std::string titleIn);


/*
addToCart()
Adds the desired movie to the cart
and allows user to make another search.
*/

void addToCart(std::vector<Video> &results);

/****************************************************************************************
Genre Search Submenu Functions
****************************************************************************************/

/*
genreSearchMain()
Main function that executes when user selects option 2 in main menu.
Allows user to view list of all movies within chosen genre.
Allows user to add individual movies from that search to their cart.
Returns user to main menu when finished.
*/

void genreSearchMain(std::vector<Video>& videoList);

/*
void displayGenreSearchMenu()
Displays the search menu for searching movies by genre.
The user arrives at this menu from the main menu if
(s)he selects option 2.
*/

void displayGenreSearchMenu();

/*
void validateGenreMenuChoice(int &choice)
Validates user input for the search by genre menu.
Works similar to "validateMainMenuChoice" function,
but accepts integers from 0 to 7.
*/

void validateGenreMenuChoice(int &choiceGenre);


/*
search function for genre, takes in vector of movies to search,
a vector of results to fill, and a genre string to search for
*/

void genreSearchVector( const std::vector<Video>& videos, 
                        std::vector<Video>& results, 
                        std::string genreIn);

/****************************************************************************************
Director Search Submenu Functions
****************************************************************************************/

/*
directorSearchMain()
Main function that executes when user selects option 3 from main menu.
Allows user to search movies by director.
Allows user to add individual movies from search to their cart.
Allows user to perform search multiple times.
Returns user to main menu when finished.
*/

void directorSearchMain(std::vector<Video>& videoList);

/*
void displayDirectorSearchMenu()
Displays the search menu for searching movies by director.
The user arrives at this menu from the main menu if
(s)he selects option 3.
*/

void displayDirectorSearchMenu();

/*
directorSearchVector()
takes a const vector of movies to search, a vector of videos to add results to, and a search term.
*/

void directorSearchVector(  const std::vector<Video>& videos, 
                            std::vector<Video>& results, 
                            std::string directorIn);

/****************************************************************************************
Movies In Cart Submenu Functions
****************************************************************************************/

/*
moviesInCartMain()
Main function that activates when user selects option 4 from the main menu.
Allows user to view movies currently in cart.
Allows user to remove movies from cart.
Allows user to view total price here?
Returns user to main menu when finished.
Possibly allows user to check out from here?
*/

void moviesInCartMain();

/*
void displayMoviesInCart()
Displays the movies the user has selected to rent.
The user arrives at this menu from the main menu if
(s)he selects option 4.
*/

void displayMoviesInCart();

/****************************************************************************************
Check Price Submenu Functions
****************************************************************************************/

/*
checkPriceMain()
Main function that executes when user selects option 5 from the main menu.
Allows user to view total price of all movies currently in their cart.
Possibly allows user to proceed to checkout/exit program?
Returns user to main menu when finished.
*/

void checkPriceMain();

/*
void displayPrice()
Displays the total price of all movies
that the user wants to rent.
The user arrives at this menu from the main menu if
(s)he selects option 5.
*/

void displayPrice();

/****************************************************************************************
Checkout Submenu Functions/End of Program Functions
****************************************************************************************/

/*
checkOutMain()
Main function that executes when user selects option 6 from the main menu.
Allows user to check out/exit program.
Allows option to return to main menu if desired.
*/
void checkOutMain();

/*
void displayCheckOut()
Displays the checkout screen and possibly ends program.
The user arrives at this menu from the main menu if
(s)he selects option 6.
*/

void displayCheckOut();
