#include "BawkBusterFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;



int main()
{
    Cart newCart;
    int mainMenuChoice = 0;
    vector<Video> videoList;  //creates an empty vector of Videos called videoList to store movie data from file
    
    if(!importMovieDataFromFile(videoList))  //read in data from CSV
        return 1;  //if the file can't be opened, immediately end the program;

    //at this point all movie data is successfully stored in the vector "videoList"

    do {
        displayMainMenu();  //displays main menu and prompts user for input
        cin >> mainMenuChoice;
        validateMainMenuChoice(mainMenuChoice);  //ensures input is an integer and between 1 and 6

        if (mainMenuChoice == 1)  //title search
            titleSearchMain(newCart, videoList);
        else if (mainMenuChoice == 2)  //genre search
            genreSearchMain(newCart, videoList);
        else if (mainMenuChoice == 3)  //director search
            directorSearchMain(newCart, videoList);
        else if (mainMenuChoice == 4)  //check cart
            moviesInCartMain(newCart);
        else if (mainMenuChoice == 5)  //calculate total
            checkPriceMain();

    } while (mainMenuChoice != 6);  //Loop again if user did not select 6 to check out

    //do checkout stuff

    return 0;
}
