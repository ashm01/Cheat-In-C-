//overloading + operator to define how to hands are added together
inline Hand Hand::operator+(const Hand& h)
{
	//creates a new hand
	Hand newHand;
	//addes this hand and the hand passed to the new hand
	newHand.add(this->hand);
	newHand.add(h.hand);
	//returns new hand
	return newHand;
}
//get hand function
inline Hand Hand::getHand()
{
	return this->hand;
}
//function to return the size of the hand
inline int Hand::size()
{
	return this->hand.size();
}

//function to determine if the hand is considered a flush
inline bool Hand::isFlush()
{
	//for loop to iterate through hand
	for (int i = 0; i < hand.size() - 1; i++)
	{
		//using the  getsuit to check whether the current and next
		//card are of the same suit
		if (hand[i].getSuit() == hand[i + 1].getSuit())
		{

		}
		else return false;//As soon as there isnt a match false is returned
	}
	return true;//if the whole hand is iterated through true is returned
}
//function to determine if the hand is considered a straight
inline bool Hand::isStraight()
{
	//First sorts the hand into ascending order
	this->sortAscending();
	//for loop to iterate through hand
	for (int i = 0; i < hand.size() - 1; i++)
	{
		int currentRank = (int)hand[i].getRank();
		int nextRank = (int)hand[i + 1].getRank();
		//using the getrank to obtain int values of the ranks to check 
		//whether the current and next card are of consecutive order
		if (currentRank + 1 == nextRank)
		{

		}
		else return false;//As soon as there isnt a match false is returned
	}
	return true;//if the whole hand is iterated through true is returned
}
//function to return the number of occurences of a given rank in the hand
inline int Hand::countRank(Card::Rank rank)
{
	//have to minus 2 as the vector begins at 0 however the lowest rank is 2
	return rankCount[(int)rank - 2];
}
//function to return the number of occurences of a given suit in the hand
inline int Hand::countSuit(Card::Suit suit)
{
	return suitCount[(int)suit ];
}
