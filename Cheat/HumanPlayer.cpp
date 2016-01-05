

#include "stdafx.h"
#include "HumanPlayer.h"

#include <iostream>
#include <string>
#include <regex>
using namespace std;


HumanPlayer::HumanPlayer()
{
}


HumanPlayer::~HumanPlayer()
{
}

//function that calls other funtions to determine which hand the user will 
//play
Bid HumanPlayer::playHand(Bid b)
{
	//gets the answer the cheat fucntion
	bool answer = this->cheat(b);
	//returns the resilt from the choose bid function
	return this->chooseBid(b, answer);
}
//function to ask the player whether he wants to call cheat
bool HumanPlayer::callCheat(Bid b)
{
	//initialise the answer from the user input
	string answer;
	cout << "Would you like to call cheat?" << endl;
	//takes in the answer
	cin >> answer;
	//if the player wants to cheat
	if (answer == "yes")
	{
		return true;
	}
	//if he doesnt want to cheat
	else if (answer == "no")
	{
		return false;
	}
	else
	{
		//if the answer was invalid it recalls this function
		cout << "Invalid answer" << endl;
		callCheat(b);
	}
}
// function to ask the player what cards he will choose for his bid
Bid HumanPlayer::chooseBid(Bid b, bool cheat)
{
	//sorts the hand into ascending order
	this->hand.sortAscending();
	cout << "Current Hand: \n" << this->hand << endl;
	//initialse variables
	Hand tempHand;
	Bid newBid;
	Card::Rank rank = Card::Rank::TWO;
	int count = 0;
	//if the player chose to cheat
	if (cheat)
	{
		//repeat process until count is incremeneted
		while (count == 0)
		{
			//gets the number of cards from the player wants to play
			cout << "How many cards would you like to play? " << endl;
			int numCardsToPlay;
			cin >> numCardsToPlay;
			//validates the user input for number of cards
			if (numCardsToPlay < 0 || numCardsToPlay > 4)
			{
				cout << "Invalid number of cards to play? " << endl;
			}
			else
			{
				//takes the rank of the bid from the player
				cout << "What rank is your bid? "
					"(number e.g king = 13, ace = 14 etc )" << endl;
				int rankInput;
				cin >> rankInput;
				//repeats the question until a valid input is take
				while (!cin && rankInput<2 || rankInput >14)
				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Invalid rank input given!" << endl;
					cout << "What rank is your bid? "
						"(number e.g king = 13, ace = 14 etc )" << endl;
					cin >> rankInput;

				}
				//casting the input to a card rank
				Card::Rank r = (Card::Rank)rankInput;
				//checking if rank given is valid, it cant be greater then
				//the current bids next rank
				if ((int)r > (int)b.getNextRank() || (int)r < (int)b.getRank())
				{
					cout << "Invalid Rank given, either too high or too low"
						<< endl;
				}
				//r is valid
				else
				{
					//loops to the amount of cards to play
					for (int i = 0; i < numCardsToPlay; i++)
					{
						cout << "What Card do you want to play for card "
							<< i + 1 << "?  (e.g. three of spades)" << endl;
						//takes the card input 
						Card c;
						cin >> c;
						//removing the card from players hand, remove 
						//function checks if valid
						if (this->hand.remove(c))
						{
							//if the check is true adds the card to the 
							//temphand
							tempHand.add(c);
						}
						//not valid card, repeat process
						else{
							cout << "Invalid Card Inputed" << endl;
							i--;
						}


					}
					// set the hand and rank of the bid to be returned
					newBid.setHand(tempHand);
					newBid.setRank(r);
					//increment count to exit while loop
					count++;
				}

			}
		}
	}
	//if player choose not to cheat
	if (!cheat)
	{
		//loop until count is incremented
		while (count == 0)
		{
			
				cout << "What rank is your bid? "
					"(number e.g king = 13, ace = 14 etc )" << endl;
				int rankInput;
				cin >> rankInput;
				while (!cin && rankInput > 14 || rankInput < 2)
				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Invalid rank input given!" << endl;
					cout << "What rank is your bid? "
						"(number e.g king = 13, ace = 14 etc )" << endl;
					cin >> rankInput;

				}
				//casting the input to a card rank
				Card::Rank r = (Card::Rank)rankInput;
				
				//checking if rank given is valid, it cant be greater then 
				//the current bids next rank
				if ((int)r > (int)b.getNextRank() || (int)r < (int)b.getRank())
				{
					cout << "Illegal Rank given, "
						"you do not hold the appropiate cards" << endl;
				}
				else
				{
					//checking if the proposed play is valid
					if (this->hand.countRank(r) > 0)
					{
						//if play is valid add all said cards from players 
						//hand to a temp hand
						for each (Card c in this->hand.hand)
						{
							if (c.getRank() == r)
							{
								tempHand.add(c);
								rank = c.getRank();
							}
						}
						//remove the temphand from the players current hand
						this->hand.remove(tempHand);
						//sets the bid rank and hand
						newBid.setHand(tempHand);
						newBid.setRank(rank);
						//increment count to exit loop
						count++;
					}
					else
					{

						cout << "Invalid Play!" << endl;
					}
				}
			}
		}

	
	//returns the bid to be played
	return newBid;
}
//function to ask the player if they would like to cheat on their turn
bool HumanPlayer::cheat(Bid b)
{
	//initialise empty string 
	string str = "";
	//checking if the user has no other option but to cheat
	if (this->hand.countRank(b.getRank()) == 0 &&
		this->hand.countRank(b.getNextRank()) == 0)
	{
		cout << "You have to cheat!" << endl;
		return true;
	}
	//getting the users answer if they would like to cheat
	while (str != "yes" || str != "no")
	{
		cout << "Would you like to cheat?" << endl;
		//taking the users answer
		cin >> str;
		//YES
		if (str == "yes")
		{
			return true;
		}
		//No
		else if (str == "no")
		{
			return false;
		}
		//if function reaches here the cheat function will be called again
		cout << "Invalid input!" << endl;
		cheat(b);
	}
}


