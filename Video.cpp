/******************************************************************************
** This is the implementation file for the Video class.
** A video has a title, genre, director, actor, and price.
** A constructor, a default constructor with junk values, get methods, 
** and a method to print video information are included
******************************************************************************/
#include <iostream>
#include "Video.hpp"

Video::Video()  //default constructor with junk values
{
    title = "AAA";
    genre = OTHER;
    director = "AAA";
    actor = "AAA";
    price = -100;
}
Video::Video(std::string titleIn, Genre genreIn, std::string directorIn, std::string actorIn, double priceIn)
{
    title = titleIn;
    genre = genreIn;
    director = directorIn;
    actor = actorIn;
    price = priceIn;
}
std::string Video::getTitle()
{
    return title;
}
Genre Video::getGenre()
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
double Video::getPrice()
{
    return price;
}
void Video::printInfo(Video videoIn)
{
    std::cout << "Title: " << videoIn.getTitle() << std::endl;
    std::cout << "Genre: " << videoIn.getGenre() << std::endl;
    std::cout << "Director: " << videoIn.getDirector() << std::endl;
    std::cout << "Actor: " << videoIn.getActor() << std::endl;
    std::cout << "Price: " << videoIn.getPrice() << std::endl;
}