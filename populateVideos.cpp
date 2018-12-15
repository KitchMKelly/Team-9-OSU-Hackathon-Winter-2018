#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Video.hpp"

using std::cout;
using std::endl;
using std::string;


string count;
int numLines = 0; //to compare output with # excel lines

string title;
string genre; //enumerated data type declared in Video.hpp
string director;
string actor;

int main()
{
	std::ifstream movie_data("movie-dataset.csv");

	if (!movie_data)
		cout << "Error: The file did not open" << endl;
	else
	{
		while(getline(movie_data, title, ',') && getline(movie_data, genre, ',') && getline(movie_data, director, ',') && getline(movie_data, actor))
		{
                	numLines += 1;
			//the below caused off by 1 error
                	/*getline(movie_data, title, ',');
                        getline(movie_data, genre, ',');
                        getline(movie_data, director, ',');
                        getline(movie_data, actor, '\n'); 
			*/
			Video vid(title, genre, director, actor);
			vid.printInfo(vid);
			vid.addToVector(vid);
			//cout << "Title: " << title << ", Genre: " << genre << ", Director: " << director << ", Main Actor/Actress: " << actor << endl;  
                	cout << "total movies is" << numLines << endl;
			//movie_data.close(); //test single line
		}
		movie_data.close(); //test all lines
        }

	return 0;
}
