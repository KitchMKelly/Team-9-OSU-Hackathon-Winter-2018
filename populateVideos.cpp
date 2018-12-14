#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;


string count;
int numLines = 0; //to compare output with # excel lines

string title;
string genre;
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
                	/*getline(movie_data, title, ',');
                        getline(movie_data, genre, ',');
                        getline(movie_data, director, ',');
                        getline(movie_data, actor, '\n'); 
			*/
			cout << "Title: " << title << ", Genre: " << genre << ", Director: " << director << ", Main Actor/Actress: " << actor << endl;  
                cout << "total movies is" << numLines << endl;
		//movie_data.close(); //test single line
		}
		movie_data.close(); //test all lines
        }

	return 0;
}
