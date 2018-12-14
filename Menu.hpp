/******************************************************************************
** This is the header file for the Menu class.
******************************************************************************/



void displayMainMenu();  //displays main menu text
void displayActorMenu();  //displays actor search submenu
void displayGenreMenu();  //displays genre search submenu
void displayDirectorMenu();  //displays director search submenu
void displayCart();  //displays titles currently in cart
double calculateTotal();  //tabulates the total price based on titles in the cart
void validateMenuChoice(int choice, int maxChoice);  //ensures menu choice is between 1 and maxChoice

//todo
void searchActor(); //return type depends on how we store movie data and implement search
void searchTitle(); //return type depends on how we store movie data and implement search
void searchDirector(); //return type depends on how we store movie data and implement search