#include "stdafx.h"
#include "Card.h"
#include <iostream>
using namespace std;



Card::Card(Card::Rank r, Card::Suit s)
{
	this->rank = r;
	this->suit = s;
}
void Card::setSuit(Suit s)
{
	this->suit = s;
}
void Card::SetRank(Rank r)
{
	this->rank = r;
}
std::ostream& operator<<(std::ostream& os, const Card& c)
{
	return os << c.getRank() << " of " << c.getSuit() << endl;;
}
//overloaded input operator for card object
std::istream& operator>>(std::istream& is, Card& c)
{
	//initiialising variables
	string of, rankInput, suitInput;
	Card::Rank rank;
	Card::Suit suit;
	//checking the input is of the correct data type	
	if (is >> rankInput >> of >> suitInput)
	{	//checking of = "of"
		if (of == "of")
		{	//checking the input of the rank input
			if (rankInput == "two")
			{
				rank = Card::Rank::TWO;
			}
			else if (rankInput == "three")
			{
				rank = Card::Rank::THREE;

			}
			else if (rankInput == "four")
			{
				rank = Card::Rank::FOUR;
			}
			else if (rankInput == "five")
			{
				rank = Card::Rank::FIVE;
			}
			else if (rankInput == "six")
			{
				rank = Card::Rank::SIX;
			}
			else if (rankInput == "seven")
			{
				rank = Card::Rank::SEVEN;
			}
			else if (rankInput == "eight")
			{
				rank = Card::Rank::EIGHT;
			}
			else if (rankInput == "nine")
			{
				rank = Card::Rank::NINE;
			}
			else if (rankInput == "ten")
			{
				rank = Card::Rank::TEN;
			}
			else if (rankInput == "jack")
			{
				rank = Card::Rank::JACK;
			}
			else if (rankInput == "queen")
			{
				rank = Card::Rank::QUEEN;
			}
			else if (rankInput == "king")
			{
				rank = Card::Rank::KING;
			}
			else if (rankInput == "ace")
			{
				rank = Card::Rank::ACE;
			}
			//checking suit input
			if (suitInput == "clubs")
			{
				suit = Card::Suit::CLUBS;
			}
			else if (suitInput == "diamonds")
			{
				suit = Card::Suit::DIAMONDS;
			}
			else if (suitInput == "hearts")
			{
				suit = Card::Suit::HEARTS;
			}
			else if (suitInput == "spades")
			{
				suit = Card::Suit::SPADES;
			}

		}
		else
		{
			cout << "Invalid Card Input" << endl;
		}
	}

	c = Card(rank, suit);

	return is;
}
//output operator overloaded ofr a suit
std::ostream& operator<<(std::ostream& os, const Card::Suit& s)
{
	//switch statement determined by the int value of the suit
	switch (s)
	{
	case Card::Suit::CLUBS:
		return os << "clubs";
	case Card::Suit::DIAMONDS:
		return os << "diamonds";
	case Card::Suit::SPADES:
		return os << "spades";
	case Card::Suit::HEARTS:
		return os << "hearts";
	default:
		return os;
	}
}

//output operator for the rank of a card
std::ostream& operator<<(std::ostream& os, const Card::Rank& r)
{
	//switch statement to print out the correct rank based on the
	//int value of the rank passed
	switch (r)
	{
	case Card::Rank::ACE:
		return os << "Ace";
	case Card::Rank::TWO:
		return os << "Two";
	case Card::Rank::THREE:
		return os << "Three";
	case Card::Rank::FOUR:
		return os << "Four";
	case Card::Rank::FIVE:
		return os << "Five";
	case Card::Rank::SIX:
		return os << "Six";
	case Card::Rank::SEVEN:
		return os << "Seven";
	case Card::Rank::EIGHT:
		return os << "Eight";
	case Card::Rank::NINE:
		return os << "Nine";
	case Card::Rank::TEN:
		return os << "Ten";
	case Card::Rank::JACK:
		return os << "Jack";
	case Card::Rank::QUEEN:
		return os << "Queen";
	case Card::Rank::KING:
		return os << "King";
	default:
		return os;
	}
}
//function to return the card value of a card
int Card::getCardValue()
{
	//checks the current rank cast as an int is less then 11
	if ((int)this->rank < 11)
	{
		//returns the current rank as an int
		return (int)this->getRank();
	}
	// if the rank is between 11 and 13
	else if ((int)this->rank < 14)
	{
		//return 10
		return 10;
	}
	else//if its an ace
	{
		return 11;
	}
}

Card::~Card()
{
}
//function to return the rank ok the card
Card::Rank Card::getRank() const
{

	return this->rank;
}
//function to return the current suit of thecard
Card::Suit Card::getSuit() const
{
	return this->suit;
}
