
// equals operator overloaded to determine the equality
//between two cards
inline bool Card::operator==(const Card& c)
{
	//checking the int values of enums against each other
	if ((int)this->getSuit() == (int)c.getSuit() &&
		(int)this->getRank() == (int)c.getRank())
	{
		return true;
	}
	return false;
}
//return the negated == operator
inline bool Card::operator!=(const Card& c)
{
	return !operator==(c);
}
//less than operator overloaded
inline bool Card::operator<(const Card& c)
{
	//again checking the interger values of the enum
	//and determining less then operation
	if ((int)this->getRank() < (int)c.getRank())
	{
		return true;
	}
	else if ((int)this->getRank() == (int)c.getRank())
	{
		if ((int)this->getSuit() < (int)c.getSuit())
		{
			return true;
		}
	}
	return false;
}
//greater then operator overloaded
inline bool Card::operator>(const Card& c)
{
	//checking integer values of the enum to determine which is greater
	if ((int)this->getRank() > (int)c.getRank())
	{
		return true;
	}
	else if ((int)this->getRank() == (int)c.getRank())
	{
		if ((int)this->getSuit() > (int)c.getSuit())
		{
			return true;
		}
	}
	return false;
}
//greater then or equals to
//returns the negated less then operator
inline bool Card::operator>=(const Card& c)
{
	return !operator<(c);
}
//less then or equals to
//returns the negated greater then operator
inline bool Card::operator<=(const Card& c)
{
	return !operator>(c);
}
//overloaded int operater used to determine the card  value
inline Card::operator int()
{
	//if the rank is less than 11 then the face value is the same
	//as the rank
	if ((int)this->rank < 11)
	{
		return (int)this->getRank();
	}
	//if its less then 14 -- 11 = jack, 12 = queen and king = 13
	// the card value is 10
	else if ((int)this->rank < 14)
	{
		return 10;
	}
	//else its ace and the value is 11
	else
	{
		return 11;
	}
}




