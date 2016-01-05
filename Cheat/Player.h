#pragma once
#include "Card.h"
#include "Hand.h"
#include "Bid.h"
//abstract player class
class Player
{
public:
	Player();
	//abstract member functions
	virtual ~Player();
	virtual void addCard(Card c) = 0;
	virtual void addHand(Hand h) = 0;
	virtual int cardsLeft() = 0;
	virtual Bid playHand(Bid b) = 0;
	virtual bool callCheat(Bid b) = 0;
	virtual Bid chooseBid(Bid b, bool cheat) = 0;
	virtual bool cheat(Bid b)=0;
protected:
	
	Hand hand;
	


};

