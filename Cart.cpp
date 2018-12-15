/******************************************************************************
** This is the implementation file for the Cart class.
** The Cart class holds the total price of the items in the Cart, the number of
** items in the cart, and all the titles inside of the Cart. This class also
** has methods to set/get all the Data members, as well as print the item
** within the cart.
******************************************************************************/
// Cart.cpp
#include "Cart.hpp"

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
** Description:	A method that takes the video vector and counts the number of
**		videos in the vector, then sets that number to the numCart
**		data member.
*****************************************************************************/

void Cart::setNumCart(std::vector<Video> vidInput);
{
	numCart = vidInput.size();
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

void Cart::setTPrice(std::vector<Video> vidInput)
{
	// Loop through the vector of Videos
	for (index = 0; index < vidInput.size(); index++)
	{
	totalPrice += vidInput.getPrice;
	}

	//!!!!!!!IF THE PRICE IS A GLOBAL VARIABLE THIS FUNCTION CAN BE 
	//RE-WRITTEN AS!!!
	//totalPrice = PRICE*numCart;
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
**		member.
*****************************************************************************/

void Cart::addVidToCart(Video videoIn)
{
	vidVector.push_back(videoIn);
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
}

/*****************************************************************************
** Description:	A method that removes the last item added to the cart
*****************************************************************************/

void Cart::unAddToCart()
{
	vidVector.pop_back();
}

/*****************************************************************************
** Description: A method that prints the title of all the video objects in
**		the cart
*****************************************************************************/

void Cart::printCart()
{
	std::cout << "You have the following items in your cart\n";
	for (index = 0; index < vidVector.size(); index++)
	{
	std::cout << vidVector[index].getTitle << std::endl;
	}
}
