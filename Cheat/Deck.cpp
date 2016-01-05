#include "stdafx.h"
#include "Deck.h"
#include <iostream>

using namespace std;

//default constructor for the deck
Deck::Deck()
{
	//using less than 4 and 15 as limits as the enum for ranks start from 
	//2 to 14
	for (int suit = 0; suit < 4; suit++)
	{
		for (int rank = 2; rank < 15; rank++)
		{
			//creates the card based on the current rank and suit and 
			//adds to deck vector
			
			Card c((Card::Rank)rank, (Card::Suit)suit);
			deck.push_back(c);
			
		}
	}
}


Deck::~Deck()
{
	
}
//function to deal the top card of the deck
Card Deck::deal()
{
	//creates a copy of the top card
	Card c = this->deck[0];
	//erases the dealt card from the deck
	deck.erase(deck.begin()); 
	//returns the dealt card
	return c;
}
//output ooperator for deck
std::ostream& operator<<(std::ostream& os,  Deck& d)
{
	//iterate through each card printing each card
	for each (Card c in d.deck)
	{
		cout << c << "\n";
	}
	
	return os;
}
