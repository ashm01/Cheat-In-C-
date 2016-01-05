#pragma once
#include <string>

class Card 
{
public:
	//enum classes rank and suit 
	enum class Suit { CLUBS= 0, DIAMONDS, HEARTS, SPADES };
	enum class Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, 
		NINE, TEN, JACK, QUEEN, KING, ACE };
	//function declarations
	Card(Rank r = Rank::ACE, Suit s = Suit::SPADES);
	~Card();
	Rank getRank() const;
	Suit getSuit() const;
	void setSuit(Suit s);
	void SetRank(Rank r);
	int getCardValue();
	inline operator int();
	//inline operator overloads
	inline bool operator < (const Card& c);
	inline bool operator > (const Card& c);
	inline bool operator <= (const Card& c);
	inline bool operator >= (const Card& c);
	inline bool operator == (const Card& c);
	inline bool operator != (const Card& c);
	

private:
	//suit and rank variables
	Suit suit;
	Rank rank;

};
//I/O operators
std::istream& operator>>(std::istream& is,  Card& c);
std::istream& operator>>(std::istream& is, const Card::Suit& s);
std::istream& operator>>(std::istream& is, const Card::Rank& r);
std::ostream& operator<<(std::ostream& os, const Card& c);
std::ostream& operator<<(std::ostream& os, const Card::Suit& s);
std::ostream& operator<<(std::ostream& os, const Card::Rank& r);


#include "Card.hh"