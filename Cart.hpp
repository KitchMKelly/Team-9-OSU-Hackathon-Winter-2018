/******************************************************************************
** This is the header file for the Cart class.
** The Cart class holds the total price of the items in the Cart, the number of
** items in the cart, and all the titles inside of the Cart. This class also
** has methods to set/get all the Data members, as well as print the item
** within the cart.
******************************************************************************/
// Cart.hpp
#ifndef CART_HPP
#define CART_HPP

#include <vector>
#include "Video.hpp"

class Cart
{
	private:
		int numCart;		// the number of items in the cart
		double totalPrice;	// total price of items of cart
		std::vector<Video> vidVector;	// a vector of video objects
	public:
		Cart();
		Cart(int, double, std::vector<Video>;
		void setNumCart(std::vector<Video> vidInput);	// takes the video vector class member and counts number of items in cart
		int getNumCart();				// returns number of items in cart
		void setTPrice(std::vector<Video> vidInput);	// takes the video vector class member and calculates the total price
		double getTPrice();				// returns the total price of of the cart
		void addVidToCart(Video);			// adds a video object to the cart
		std::vector<Video> getTitles();			// returns a vector of videos objects in the cart
		void printCart();				// prints the items in the cart;
};

#endif
