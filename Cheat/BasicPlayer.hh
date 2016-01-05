//function to add a card to the players hand
inline void BasicPlayer::addCard(Card c)
{
	this->hand.add(c);
}
//function to add an existing hand to the players hand
inline void BasicPlayer::addHand(Hand h)
{
	this->hand.add(h);

}
//function to return the amount of cards left in the players hand
inline int BasicPlayer::cardsLeft()
{
	return this->hand.hand.size();
}
//function to return the player's current hand
inline Hand BasicPlayer::getHand()
{
	return this->hand;
}