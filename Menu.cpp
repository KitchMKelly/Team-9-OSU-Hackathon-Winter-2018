/******************************************************************************
** This is the implementation file for the Menu class.
******************************************************************************/
#include <iostream>
#include "Menu.hpp"




void displayMainMenu()
{
    std::cout << "Welcome to Blockbuster!" << std::endl << std::endl;
    std::cout << "View movies with the following options:" << std::endl;
    std::cout << "1. Search by Title" << std::endl;
    std::cout << "2. Search by Genre" << std::endl;
    std::cout << "3. Search by Director" << std::endl;
    std::cout << "4. Check Cart" << std::endl;
    std::cout << "5. Calculate Total" << std::endl;
    std::cout << "6. Exit" << std::endl << std::endl;
    std::cout << "Choice: ";
}
void displayGenreMenu()
{
    std::cout << "You have selected Search by Genre" << std::endl << std::endl;
    std::cout << "Please select genre:" << std::endl;
    std::cout << "1. ACTION" << std::endl;
    std::cout << "2. ADVENTURE" << std::endl;
    std::cout << "3. ANIMATION" << std::endl;
    std::cout << "4. COMEDY" << std::endl;
    std::cout << "5. DRAMA" << std::endl;
    std::cout << "6. HORROR" << std::endl;
    std::cout << "7. ROMANCE" << std::endl;
    std::cout << "8. SCIFI" << std::endl;
    std::cout << "9. OTHER" << std::endl;    
    std::cout << "10. Return to Main Menu" << std::endl << std::endl;
    std::cout << "Choice: ";    
}
void displayActorMenu() //not sure if we actually need this
{
    std::cout << "You have selected Search by Actor" << std::endl << std::endl;
    std::cout << "Please enter a name (first last), or enter 0 to return to the Main Menu:" << std::endl;
}
void displayDirectorMenu()
{
    std::cout << "You have selected Search by Director" << std::endl << std::endl;
    std::cout << "Please enter a name (first last), or enter 0 to return to the Main Menu:" << std::endl;
}
void displayCart()
{

}
double calculateTotal()
{

}
void validateMenuChoice(int &choice, int maxChoice)
{
    while(!std::cin || choice < 1 || choice > maxChoice)
    {
        std::cout << "Error. Please make a selection between 1 and " << maxChoice << "." << std::endl;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cin >> choice;
    }
}