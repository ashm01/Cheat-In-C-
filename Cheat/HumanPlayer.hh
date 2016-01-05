//function to add a card to the players current hand
inline void HumanPlayer::addCard(Card c)
{
	//using the add card function from the hand class
	this->hand.add(c);
}
//function to add a hand to the players current hand
inline void HumanPlayer::addHand(Hand h)
{
	this->hand.add(h);
}
//function to return the numbe of cards a player has left
inline int HumanPlayer::cardsLeft()
{
	return this->hand.hand.size();
}
//function that returns the players current hand
inline Hand HumanPlayer::getHand()
{
	return this->hand;
}