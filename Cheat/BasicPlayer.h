#pragma once
#include "Player.h"


class BasicPlayer : public Player
{
public:
	BasicPlayer();
	~BasicPlayer();
	inline void addCard(Card c);
	inline void addHand(Hand h);
	inline int cardsLeft();
	Bid playHand(Bid b);
	bool callCheat(Bid b);
	Bid chooseBid(Bid b,  bool cheat);
	bool cheat(Bid b);
	inline Hand getHand();

private:
};
#include "BasicPlayer.hh"

