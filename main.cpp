#include "BawkBusterFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
  Cart newCart;
  vector<Video> videoList;  //creates an empty vector of Videos called videoList to store movie data from file
    
  if(!importMovieDataFromFile(videoList))  //read in data from CSV
    return 1;  //if the file can't be opened, immediately end the program;

  mainMenu(newCart, videoList);

  return 0;
}