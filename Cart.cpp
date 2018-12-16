/******************************************************************************
** This is the implementation file for the Cart class.
** The Cart class holds the total price of the items in the Cart, the number of
** items in the cart, and all the titles inside of the Cart. This class also
** has methods to set/get all the Data members, as well as print the item
** within the cart.
******************************************************************************/
// Cart.cpp
#include "Cart.hpp"
#include "Video.hpp"
#include <iostream>

/*****************************************************************************
** Description:	The default constructor for the Cart class. Initializes the
**		all datamembers of the Cart class as 0 or empty
*****************************************************************************/

Cart::Cart()
{
	// Set number of items in cart to 0
	numCart = 0;
	// Set total price of items in cart to 0
	totalPrice = 0;
}

/*****************************************************************************
** Description:	A method that takes an int and sets it to the numCart data
**		member
*****************************************************************************/

void Cart::setNumCart(int input)
{
	numCart = input;
}

/*****************************************************************************
** Description:	A method that returns the numCart data member
*****************************************************************************/

int Cart::getNumCart()
{
	return numCart;
}

/*****************************************************************************
** Description: A method that calculates the price of all the videos in the
**		cart and sets it to the totalPrice data member.
*****************************************************************************/

void Cart::setTPrice()
{
	/*// Loop through the vector of Videos
	for (int index = 0; index < vidInput.size(); index++)
	{
	totalPrice += vidInput.getPrice;
	}
	*/

	//!!!!!!!IF THE PRICE IS A GLOBAL VARIABLE THIS FUNCTION CAN BE 
	//RE-WRITTEN AS!!!
	totalPrice = PRICE*numCart;
}

/*****************************************************************************
** Description:	A method that returns the totalPrice data member.
*****************************************************************************/

double Cart::getTPrice()
{
	return totalPrice;
}

/*****************************************************************************
** Description: A method that adds a Video object to the Video vector data
**		member and updates the other data members
*****************************************************************************/

void Cart::addVidToCart(Video videoIn)
{
	vidVector.push_back(videoIn);
	numCart++;
	totalPrice += PRICE; //adds the price after every additional video is put in;
	std::cout << "in addVidToCart " << numCart << " price " << totalPrice << std::endl;
	for(int i = 0; i < vidVector.size(); i++)
	{
		std::cout << vidVector[i].getTitle() << std::endl;
	}
}

/*****************************************************************************
** Description:	A method that returns the vector of Video objects data member
*****************************************************************************/

std::vector<Video> Cart::getVideos()
{
	return vidVector;
}

/*****************************************************************************
** Description:	A method to remove all the contents of the cart
*****************************************************************************/

void Cart::emptyCart()
{
	vidVector.clear();
	numCart = 0;
	totalPrice = 0;
}

/*****************************************************************************
** Description:	A method that removes the last item added to the cart
*****************************************************************************/

void Cart::unAddToCart()
{
	vidVector.pop_back();
	numCart--;
	totalPrice -= PRICE;
}

/*****************************************************************************
** THIS MIGHT BE PLACED INTO A MENU FUNCTION
** Description: A method that prints the title of all the video objects in
**		the cart
*****************************************************************************/
/*
void Cart::printCart()
{
	std::cout << "You have the following items in your cart\n";
	for (int index = 0; index < vidVector.size(); index++)
	{
	Video tempVid = vidVector[index];
	std::string tempString = tempVid.getTitle;

	std::cout << tempString << std::endl;
	}
}
*/
