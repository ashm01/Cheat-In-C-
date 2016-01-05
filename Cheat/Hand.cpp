#include "stdafx.h"
#include "Hand.h"
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


Hand::Hand()
{
	
}
//default constructor, takes a vector of cards
Hand::Hand(vector<Card> cards)
{
	//adds all the cards in the vector to the current hand
	for each (Card c in cards)
	{
		this->hand.push_back(c);
	}
}


Hand::~Hand()
{
}
//function to add a card to the current hand
void Hand::add(Card c)
{
	//gets the int values of the rank and suit to be used
	//to increment the rank and suit count
	int rank = (int)c.getRank();
	int suit = (int)c.getSuit();
	//adds the cards to the hand
	hand.push_back(c);
	//have to minus two has the enum values dont correspond to the correct
	//place in the vector
	rankCount[rank-2]++;
	suitCount[suit]++;

}
//function to add a hand to the current hand
void Hand::add(Hand h)
{
	//iterate through the given hand adding each card 
	for each (Card temp in h.hand)
	{
		this->add(temp);
	}
}
//function to add a vector to the current hand
void Hand::add(vector<Card> c)
{
	//iterate through the given vector adding each card 
	for each (Card temp in c)
	{
		this->add(temp);
	}
}
//function to remove a card from the current hand, returns true or false
bool Hand::remove(Card c)
{
	//iteration through the hand
	for (int i = 0; i < hand.size();i++)
	{
		//checking if the current card equals the card were looking or
		if (c == hand[i])
		{
			//gets the rank and suit then erases the card from the hand
			int rank = (int)hand[i].getRank();
			int suit = (int)hand[i].getSuit();
			hand.erase(hand.begin()+i);
			//decrease the rank and suit count
			rankCount[rank-2]--;
			suitCount[suit]--;
			return true;
		}
	}
	return false;
}
//function to remove a given hand of cards from the current hand
bool Hand::remove(Hand handToRemove)
{
	//initialise counter
	int count = 0;
	//vector of temp cards
	vector<Card> tempCards;
	//iteratre through hand
	for (int i = 0; i < hand.size(); i++)
	{
		for (int j = 0; j < handToRemove.hand.size(); j++)
		{
			if (hand[i] == handToRemove.hand[j])
			{
				
				//if there is match, a copy is stored in the temp vector
				tempCards.push_back(hand[i]);
				count++;
			}
		}
	}
	//checking whether all the cards in the parsed hand where matched in 
	//the current hand
	if (count == handToRemove.hand.size())
	{
		
		for each (Card c in tempCards)
		{
			//removing each card
			remove(c);
			
		}
		return true;
	}
	else return false;

	
	
}
//function to remove a card in a given position in the hand
Card Hand::remove(int pos)
{
	//create temp card
	Card temp = this->hand[pos];
	//erase the card in the given position
	this->hand.erase(hand.begin() + pos);
	//return the temp card
	return temp;
}
//outstream operator overloaded to print out all the hands contents
std::ostream& operator<<(std::ostream& os, Hand& h)
{
	for each (Card c in h.hand)
	{
		cout << c << "\n";
	}

	return os;
}
//function to sort the hand into ascending order based on their rank then suit
void Hand::sortAscending()
{
	//using the sort algoirthm to sort the hand into ascending order
	//(default way) < operator was defined in the card class 
	std::sort(hand.begin(), hand.end());
}
//function to sort the hand into descending order based on their rank then suit
void Hand::sortDescending()
{
	//using the sort algoirthm to sort the hand into descending order using 
	//the greater function
	std::sort(hand.begin(), hand.end(), greater<int>());
}