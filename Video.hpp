/******************************************************************************
** This is the header file for the Video class.
** A video has a title, genre, director, actor, and price.
** A constructor, a default constructor with junk values, get methods, 
** and a method to print video information are included
******************************************************************************/
#include <string>

#ifndef VIDEO_HPP
#define VIDEO_HPP

enum Genre {ACTION, ADVENTURE, ANIMATION, COMEDY, DRAMA, HORROR, ROMANCE, SCIFI, OTHER};

class Video
{   private:
        std::string title;
        Genre genre;
        std::string director;
        std::string actor;  //not sure if we need this, our dataset only has 1 per movie...
        double price;  //if we're making everything the same price we might not need this

    public:
        Video();  //default constructor with junk values
        Video(std::string title, Genre genre, std::string director, std::string actor, double price);
        std::string getTitle();
        Genre getGenre();
        std::string getDirector();
        std::string getActor();
        double getPrice();
        void printInfo(Video videoIn);
};
#endif