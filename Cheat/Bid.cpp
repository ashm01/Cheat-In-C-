#include "stdafx.h"
#include "Bid.h"
#include <iostream>
using namespace std;

//default constructor
Bid::Bid()
{
	this->rank = Card::Rank::TWO;
}


Bid::~Bid()
{
}
//value based constructor, takes an hand and rank
Bid::Bid(Hand h, Card::Rank r)
{
	this->hand = h;
	this->rank = r;
}
//output operator overloaded to determine how an bid is printed
std::ostream& operator<<(std::ostream& os, Bid& b)
{
	return os <<"Cards in bid: "<< b.getHand() << "\n Bid Rank: "
		<<b.getRank();
}
//function to check whether the bid is valid
bool Bid::isValid()
{
	//for each to iterate through each card in the current bid
	for each (Card c in this->hand.hand)
	{
		//as soon as there isnt a match false is returned
		if ((int)c.getRank() != (int)this->rank)
		{
			return false;
		}
	}
	//if the iteraion completes true is returned
	return true;
}


