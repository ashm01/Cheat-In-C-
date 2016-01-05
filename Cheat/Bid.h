#pragma once
#include "Card.h"
#include "Hand.h"
class Bid
{
public:
	Bid();
	Bid(Hand h, Card::Rank r);
	~Bid();
	inline void setHand(Hand h);
	inline void setRank(Card::Rank r);
	inline Hand getHand();
	inline int getCount();
	inline Card::Rank getRank();
	inline Card::Rank getNextRank();
	bool isValid();
private:
	Hand hand;
	Card::Rank rank;

};

std::ostream& operator<<(std::ostream& os, Bid& b);

#include "Bid.hh"