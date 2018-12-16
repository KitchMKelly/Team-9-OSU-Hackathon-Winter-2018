/******************************************************************************
** This is the implementation file for the Video class.
** A video has a title, genre, director, actor, and price.
** A constructor, a default constructor with junk values, get methods, 
** and a method to print video information are included
******************************************************************************/
#include <iostream>
#include <vector>
#include "Video.hpp"

Video::Video()  //default constructor with junk values
{
    title = "AAA";
    genre = "OTHER";
    director = "AAA";
    actor = "AAA";
    //price = -100;
}
Video::Video(std::string titleIn, std::string genreIn, std::string directorIn, std::string actorIn)
{
    title = titleIn;
    genre = genreIn;
    director = directorIn;
    actor = actorIn;
    //price = PRICE;
}
std::string Video::getTitle()
{
    return title;
}
std::string Video::getGenre()
{
    return genre;
}
std::string Video::getDirector()
{
    return director;
}
std::string Video::getActor()
{
    return actor;
}
/*double Video::getPrice()
{
    return PRICE;
}*/
void Video::printInfo(Video videoIn)
{
    std::cout << "Title: " << videoIn.getTitle() << std::endl;
    std::cout << "Genre: " << videoIn.getGenre() << std::endl;
    std::cout << "Director: " << videoIn.getDirector() << std::endl;
    std::cout << "Actor: " << videoIn.getActor() << std::endl;
    //std::cout << "Price: " << videoIn.getPrice() << std::endl;
}

void Video::addToVector(Video videoIn)
{
    //vector<Video> videos;
    videos.push_back(videoIn);
}

Video Video::searchTitle(const std::vector<Video>& videos, std::string titleIn)
{
    Video result, temp;
    int index = 0;
    int size = videos.size();
    bool found = false;
    while(index < size && !found)
    {
       temp = videos[index];
       if(temp.getTitle() == titleIn)
       {
          found = true;
          result = videos[index]; 
       }
       index++;
    }
    return result;
}

    
