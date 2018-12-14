/******************************************************************************
** This is the header file for the Menu class.
******************************************************************************/

const int MAINMENUMAX = 6; //stores max choice of main menu
const int GENREMENUMAX = 10; //stores max choice of genre menu

void displayMainMenu();  //displays main menu text
void displayGenreMenu();  //displays genre search submenu
void displayDirectorMenu();  //displays director search submenu
void displayCart();  //displays titles currently in cart
double calculateTotal();  //tabulates the total price based on titles in the cart
void validateMenuChoice(int &choice, int maxChoice);  //ensures menu choice is between 1 and maxChoice

//todo
void searchTitle(); //return type depends on how we store movie data and implement search
void searchDirector(); //return type depends on how we store movie data and implement search

//we can also search by actor, but our dataset only has one per film so it's a bit wonky and inconsistent.
//e.g. the first and third LotR movie lists Christopher Lee, but the second lists Orlando Bloom

void displayActorMenu();  //displays actor search submenu
void searchActor(); //return type depends on how we store movie data and implement search