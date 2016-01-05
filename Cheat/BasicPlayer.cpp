#include "stdafx.h"
#include "BasicPlayer.h"
#include <iostream>
using namespace std;
//default constructor
BasicPlayer::BasicPlayer()
{
}
//destrcutor
BasicPlayer::~BasicPlayer()
{
}
//function to deterine what cards the player will play
Bid BasicPlayer::playHand(Bid b)
{
	//calls the cheat function to determine whether 
	//the player needs to cheat
	bool answer = this->cheat(b);
	//passes the answer and current bid the choosebid function
	//which returns the players bid
	return this->chooseBid(b, answer);
}
//function to determine if the player needs to call cheat on the current bid
bool BasicPlayer::callCheat(Bid b)
{
	//checking if the player has more cards of the current bids rank then 
	//its possible to without the play being a cheat
	//if player plays 3 aces and player has 2....3 is > 2 so they must
	//be cheating
	if (b.getCount() > (4 - this->hand.countRank(b.getRank())))
	{
		return true;
	}
	else
	{
		return false;
	}
}
Bid BasicPlayer::chooseBid(Bid b, bool cheat)
{
	//Creating a tempory hand
	Hand tempHand;
	//Initialising the bid to be played
	Bid newBid;
	//sorts the hand into ascending order
	this->hand.sortAscending();
	//initialise rank of the new bid
	Card::Rank rank;
	// This implys from boolean cheat method that the hand 
	// Does contain a card with the rank value equal to or one above the
	// the bid rank value
	if (cheat == false)
	{
		
		//if there is a a card with the same rank value as the bid
		if (this->hand.countRank(b.getRank()) > 0)
		{
			//iterate through each card in the hand
			for each (Card c in this->hand.hand)
			{
				//if there is a match add the card to the temp hand
				if (c.getRank() == b.getRank())
					tempHand.add(c);
			}
			//sets rank of the bid
			rank = b.getRank();

			//removing the cards from the players hand
			cout << hand.size() << endl;
			this->hand.remove(tempHand);
			cout << hand.size() << endl;
		}
		//playing cards of the next rank from the players hand
		else
		{
			//iterate through each card in the hand
			for each (Card c in this->hand.hand)
			{
				//if there is a match add the card to the temp hand
				if (c.getRank() == b.getNextRank())
					tempHand.add(c);
			}
			//sets rank of the bid
			rank = b.getNextRank();
			//removing the cards from the players hand
			this->hand.remove(tempHand);
		}
		//Initialising the bid to be played
		newBid.setHand(tempHand);
		newBid.setRank(rank);
		cout << "current bid cards: " << newBid.getHand() << "bid rank = " 
			<< newBid.getRank() << endl;
	}
	//When the player must cheat on his turn
	else if (cheat == true)
	{
		//initialise rank of the new bid
		Card::Rank rank;
		//Initialising a random int which will be used to select
		//the random card from the hand and the random rank
		int randomIndex = rand() % this->hand.size();
		int randomRank = rand() % 2;
		//removes the card from the random position
		Card removed = this->hand.remove(randomIndex);
		//adds the card to the temp hand
		tempHand.add(removed);
		//sets the rank based on the random rank int
		if (randomRank == 0)
		{
			rank = b.getRank();
		}
		else
		{
			rank = b.getNextRank();
		}
		//Initialising the bid to be played
		
		newBid.setHand(tempHand);
		newBid.setRank(rank);
		cout << "current bid cards: " << newBid.getHand() << "bid rank = "
			<< newBid.getRank() << endl;
	}
	//returns the players bid
	cout << "current bid cards: "<<newBid.getHand() <<"bid rank = "
		<< newBid.getRank( )<<endl;
	return newBid;
}
//function to return true or false is the player needs to cheat
bool BasicPlayer::cheat(Bid b)
{
	//checking if the player ha cards of the current or next rank
	if (this->hand.countRank(b.getRank()) > 0
		|| this->hand.countRank(b.getNextRank()) > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

