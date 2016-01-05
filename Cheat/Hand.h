#pragma once
#include "Card.h"
#include <vector>
using std::vector;
class Hand
{
public:
	Hand();
	Hand(vector<Card> c);
	~Hand();
	void add(Card c);
	void add(vector<Card> c);
	void add(Hand h);
	bool remove(Card c);
	bool remove(Hand h);
	Card remove(int pos);
	inline int size();
	inline Hand getHand();
	vector<Card> hand;
	void sortAscending();
	void sortDescending();
	inline bool isFlush();
	inline bool isStraight();
	inline int countRank(Card::Rank rank);
	inline int countSuit(Card::Suit suit);
	inline Hand operator+(const Hand& h);

private:
	//empty vectors for the suit and rank counts
	std::vector<int> rankCount{ 13, 0 };
	vector<int> suitCount{4,0};
	
};

std::ostream& operator<<(std::ostream& os, Hand& h);

#include "Hand.hh"

