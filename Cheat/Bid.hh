//Function to set the hand of the bid
inline void Bid::setHand(Hand h)
{
	//assigns the parameter to this hand
	this->hand = h;
}
//function to set the rank of the current bid 
inline void Bid::setRank(Card::Rank r)
{
	//assigning parameter
	this->rank = r;
}
//function to return the current hand of the bid
inline Hand Bid::getHand()
{
	return this->hand;
}
//function to count the number of cards in the bid
inline int Bid::getCount()
{
	return this->hand.size();
}
//funcion that returns the current rank of the bid
inline Card::Rank Bid::getRank()
{
	return this->rank;
}
//function that returns the next rank of the bid(one above the current rank)
//if its ace it reverts back to two
inline Card::Rank Bid::getNextRank()
{
	//checking the current rank value as an integer is == 14 if so
	//rank becomes 2 again
	if ((int)this->rank == 14)
	{
		//return rank two
		return Card::Rank::TWO;
	}
	else
	{
		//return the next rank
		int i = (int)this->rank + 1;
		Card::Rank r = (Card::Rank)i;
		return r;
	}
}