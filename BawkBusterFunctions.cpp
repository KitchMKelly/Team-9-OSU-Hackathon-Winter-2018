/*
This file contains the functions used in the BawkBuster submission
at the BeaverHacks Winter 2018 Hackathon.
*/

#include "BawkBusterFunctions.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/****************************************************************************************
Main Menu Functions
****************************************************************************************/
/*
takes a vector of viedos by reference, fills with movie info from file
*/

bool importMovieDataFromFile(vector<Video> &videoList)
{
    string title;
    string genre;
    string director;
    string actor;
    
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
        getline(inputFile,director,',');  //director = director from file
        getline(inputFile,actor,'\n');  //director = director from file

        videoList.push_back(Video(title, genre, director, actor)); 
    }

    inputFile.close();
    return true;
}

/*
displayMainMenu()
Displays the main menu choices for the user to choose from
*/

void displayMainMenu()
{
	system("CLS");	//Clear screen before displaying menu
	cout << "Welcome to BawkBuster!\n" << endl;
	cout << "Select on of the following options:\n" << endl;
	cout << "1: Search movies by Title" << endl;
	cout << "2: Search movies by Genre" << endl;
	cout << "3: Search movies by Director" << endl;
	cout << "4: Review movies in your cart" << endl;
	cout << "5: Check the rental price of movies in your cart" << endl;
	cout << "6: Check Out\n" << endl;
	cout << "Please enter a number between 1 and 6" << endl;
}

/*
validateMainMenuChoice(int &choice)
Validates the user's input for the main menu options.
If the user's input is not an integer, or the input
integer is out of bounds (larger than 6 or smaller than 1), 
the while loop will activate and prompt the user to reenter their choice.
*/

void validateMainMenuChoice(int &choiceMain)
{
	//While the user input is not of the "int" datatype,
	//or the user input is larger than 6 or smaller than 1
	while (!cin || choiceMain > 6 || choiceMain < 1)
	{
		cin.clear();	//Clear bad input flag
		cin.ignore(10000, '\n');	//Discard input
		cout << "Please enter a number between 1 and 6" << endl;
		cin >> choiceMain;
	}
}

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

void titleSearchMain(vector<Video>& videoList)  //Needed to pass the vector so it's available to search
{
	vector<Video> results;		//Initialize an empty vector of movie results
	string title = "";			//Initalize new string to hold user input

	cin.clear();				//Clear bad input flag
	cin.ignore(10000, '\n');	//Discard input
	system("CLS");				//Clear screen before displaying menu
	cout << "Search Movies by: Title\n" << endl;
	cout << "Enter the title of the movie you are searching for,\n" 
		<< "or enter '0' to return to Main Menu." << endl;

	getline(cin, title);		//Get user input, store in 'title'
	while (title != "0")		//As long as the user doesn't enter '0',
								//(s)he can search as many times as desired.
	{							
		//search for movie titles, return results (if any)
		titleSearchVector(videoList, results, title);
		if (results.empty())  //if results is empty, we didn't find it
		{
			system("CLS");
			cout << "Movie not found\n" << endl;
		}
		else
		{
			system("CLS");
			cout << "Movie found!!\n";  //result now holds the address of the movie!!
			addToCart();				//User decides if (s)he wants to add the movie to the cart,
										//and continues searching.
		}
		results.clear(); //delete everything from the vector to prepare for the next search
		cout << "Please enter another movie title,\n"
			 << "or enter '0' to return to Main Menu." << endl;
		getline(cin, title);
	}
	//TODO: Function to add user selections to cart
}

void titleSearchVector(const vector<Video>& videos, vector<Video>& results, string titleIn)  
//takes a const vector of movies to search, a vector of videos to add results to, and a search term.
{
    Video temp;  //creates a temporary video to hold values as we process vector
    int index = 0;
    int size = videos.size();
    while(index < size)
    {
       	temp = videos[index];  //set temp equal to the video at [index]
       	if(temp.getTitle() == titleIn)
    		results.push_back(videos[index]);  //if video is found, add it to results
       	index++;
    }
}


/*
addToCart()
Adds the desired movie to the cart
and allows user to make another search.
*/

void addToCart()
{
	char addDecision;		//variable to hold user choice
	cout << "Would you like to add this movie to your cart? (Y/N)" << endl;
	cin >> addDecision;
	
	//Verify user input
	while (!(cin >> addDecision) || (toupper(addDecision) != 'Y' && toupper(addDecision) != 'N'))
	{
		cout << "Please enter either 'Y' to add the movie to your cart, " << endl;
		cout << "or enter 'N' to start a new search." << endl;
		cin >> addDecision;
	}

	//Action based on user input
	if (toupper(addDecision) == 'Y')
	{
		//add movie to cart
		//display confirmation message ("movieName" was added to your cart!)
	}
	else if (toupper(addDecision) == 'N')
	{
		//display confirmation message ("movieName" was not added to your cart!)
	}
}

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

void genreSearchMain()
{
	displayGenreSearchMenu();
	//TODO: Switch to direct searches by genre
	//TODO: Function to add individual movies from the searched genre to the cart
	//TODO: Function to allow multiple searches of different genres
	//TODO: Function to return to main menu
}

/*
void displayGenreSearchMenu()
Displays the search menu for searching movies by genre.
The user arrives at this menu from the main menu if
(s)he selects option 2.
*/

void displayGenreSearchMenu()
{
	system("CLS");	//Clear screen before displaying menu
	cout << "Search Movies by: Genre\n" << endl;
	cout << "What genre of movie are you interested in watching?\n" << endl;
	cout << "1: Action/Adventure" << endl;
	cout << "2: Comedy" << endl;
	cout << "3: Romance" << endl;
	cout << "4: Horror" << endl;
	cout << "5: Animated" << endl;
	cout << "6: Other" << endl;
	cout << "7: Return to Main Menu\n" << endl;
	cout << "Please enter a choice between 1 and 7" << endl;
}

/*
void validateGenreMenuChoice(int &choice)
Validates user input for the search by genre menu.
Works similar to "validateMainMenuChoice" function,
but accepts integers from 1 to 7.
*/

void validateGenreMenuChoice(int &choiceGenre)
{
	while (!(cin >> choiceGenre) || choiceGenre > 7 || choiceGenre < 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter a choice between 1 and 7" << endl;
		cin >> choiceGenre;
	}
}

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

void directorSearchMain()
{
	displayDirectorSearchMenu();
	//TODO: Accept user input and search dataset using the user's input
	//TODO: Function to add individual movies to cart
	//TODO: Function to allow multiple searches
	//TODO: Function to return to main menu
}

/*
void displayDirectorSearchMenu()
Displays the search menu for searching movies by director.
The user arrives at this menu from the main menu if
(s)he selects option 3.
*/

void displayDirectorSearchMenu()
{
	system("CLS");	//Clear screen before displaying menu
	cout << "Search movies by: Director\n" << endl;
	cout << "Enter the name of the director,\n"
		<< "or type 'exit' to return to the main menu." << endl;
}

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

void moviesInCartMain()
{
	displayMoviesInCart();
	//TODO: Allow users to remove movies from cart
	//TODO: Function to display price here?
	//TODO: Function to return user to main menu
	//TODO: Function to allow user to check out/exit program?
}

/*
void displayMoviesInCart()
Displays the movies the user has selected to rent.
The user arrives at this menu from the main menu if
(s)he selects option 4.
*/

void displayMoviesInCart()
{
	system("CLS");	//Clear screen before displaying menu
	cout << "Here's what's in your cart:" << endl;
	//TODO: Show what's in the user's cart
	system("pause");	//Wait for user to press 'enter'
}

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

void checkPriceMain()
{
	displayPrice();
	//TODO: Function to allow user to check out/exit program?
	//TODO: Function to return user to main menu
}

/*
void displayPrice()
Displays the total price of all movies
that the user wants to rent.
The user arrives at this menu from the main menu if
(s)he selects option 5.
*/

void displayPrice()
{
	cout << "Current price of the movies in your cart:\n" << 
		//whatever variable holds total price <<
		endl;
	system("pause");	//Waits for user to press 'enter'
						//before returning to main menu
}

/****************************************************************************************
Checkout Submenu Functions/End of Program Functions
****************************************************************************************/

/*
checkOutMain()
Main function that executes when user selects option 6 from the main menu.
Allows user to check out/exit program.
Allows option to return to main menu if desired.
*/
void checkOutMain()
{
	displayCheckOut();
}

/*
void displayCheckOut()
Displays the checkout screen and possibly ends program.
The user arrives at this menu from the main menu if
(s)he selects option 6.
*/

void displayCheckOut()
{
	cout << "Thank you for choosing BawkBuster!" << endl;
	cout << "Your total price is: " <<
		//whatever variable is used for total price <<
		endl;
	cout << "Enjoy your movies!" << endl;
	system("pause");	//Waits for user to press "enter"
						//before exiting program.
}