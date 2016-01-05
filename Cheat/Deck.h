#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using std::vector;
#include "Card.h"
class Deck
{
public:
	Deck();
	~Deck();
	//Function declarations
	Card deal();
	inline int size();
	inline void shuffleDeck();
	vector<Card> deck;
private:
};
//I/O operators
std::ostream& operator<<(std::ostream& os,  Deck& d);
std::istream& operator>>(std::istream& is, const Deck& d);

#include "Deck.hh"