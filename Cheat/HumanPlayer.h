#pragma once
#include "Player.h"
class HumanPlayer : public Player
{
public:
	HumanPlayer();
	~HumanPlayer();
	inline void addCard(Card c);
	inline void addHand(Hand h);
	inline int cardsLeft();
	Bid playHand(Bid b);
	bool callCheat(Bid b);
	Bid chooseBid(Bid b,  bool cheat);
	bool cheat(Bid b);
	inline Hand getHand();
};

#include "HumanPlayer.hh"
