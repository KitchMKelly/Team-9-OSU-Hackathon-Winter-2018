#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string count;
int numLines = 0;

string title;
string genre;
string director;
string actor;

int main()
{
	ifstream movie_data("movie-dataset.csv");

		if (!movie_data)
		cout << "Error: The file did not open" << endl;
	else
	{
		while(getline(movie_data, count))
		{
                	numLines += 1;
                	getline(movie_data, title, ',');
                        getline(movie_data, genre, ',');
                        getline(movie_data, director, ',');
                        getline(movie_data, actor, ','); 
		cout << "total movies is" << numLines << endl;
		movie_data.close();
	}

	return 0;
}
