/******************************************************************************
** This is the header file for the Video class.
** A video has a title, genre, director, actor, and price.
** A constructor, a default constructor with junk values, get methods, 
** and a method to print video information are included
******************************************************************************/
#include <string>
#include <vector>

#ifndef VIDEO_HPP
#define VIDEO_HPP

class Video
{   private:
        std::string title;
        std::string genre;
        std::string director;
        std::string actor;  //not sure if we need this, our dataset only has 1 per movie...
        //const double PRICE = 1.99;  //if we're making everything the same price we might not need this
	std::vector<Video> videos;
    public:
        Video();  //default constructor with junk values
        Video(std::string title, std::string genre, std::string director, std::string actor);
        std::string getTitle();
        std::string getGenre();
        std::string getDirector();
        std::string getActor();
        //double getPrice();
        void printInfo(Video videoIn);
	void addToVector(Video videoIn);
        void searchTitle(const std::vector<Video>& videos, std::string titleIn);
};
#endif
