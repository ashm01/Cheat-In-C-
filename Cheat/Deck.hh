//function to return the size of the deck
inline int Deck::size()
{
	//int counts the size
	int size = 0;
	//for each loop to iterate through the deck
	for each (Card c in this->deck)
	{
		//increments the size each iteration
		size++;
	}
	//returns size
	return size;
}
//function to shuffle the deck of cards
inline void Deck::shuffleDeck()
{
	//creates a new vector which is a copy of the original dek
	vector<Card> Copy(this->deck);
	//initialise counter, max and current
	int counter, max, current;
	//max the size of the current
	max = this->deck.size();
	//random number with the time seeded
	srand((unsigned)time(NULL));
	//clears the old deck
	this->deck.clear();
	// for loop to iterate from 0 to 51 
	for (int counter = 0; counter < max; counter++)
	{
		//randomly selects from the copy and adds to the original deck
		current = rand() % Copy.size();
		this->deck.push_back(Copy[current]);
		//deleting from the copy to avoid duplicates
		Copy.erase(Copy.begin() + current);
	}
}