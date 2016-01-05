#include "stdafx.h"
#include "Game.h"
#include <iostream>
using namespace std;

//default constructor for the cheat game which uses the min(5) players
Game::Game()
{
	Game(this->MINPLAYERS);
}
//constructor that takes the number of players as an parameter
Game::Game(int n)
{
	//initialise number players to n
	this->numPlayers = n;
	//creating the number of players that was passed
	for (int i = 0; i < this->numPlayers; i++)
	{
		//CHANGE THE PLAYER TYPE TO BASIC FOR COMPUTER ONLY GAME OR
		//HUMAN TO BE A HUMAN CONTROLLED GAME
		BasicPlayer p;
		//Adds players to player vector
		players.push_back(p);
	}
	//initialise current player to position 0
	this->currentPlayer = 0;
}

Game::~Game()
{

}

//function to play a turn of cheat
bool Game::playTurn()
{
	
	cout << "Current Bid = " << currentBid.getHand() << endl;
	//current bid equals the result from the current player playing a hand
	//based on the current bid
	currentBid = players[currentPlayer].playHand(currentBid);
	//sets the rank of the current bid 
	currentBid.setRank(currentBid.getRank());
	cout << "Player bid = " << currentBid.getHand() << endl;
	//add the current bid to the discards card pile
	discards.add(currentBid.getHand());
	//initialising cheat variable to false
	bool cheat = false;
	//fopr loop to iterate through all the players and while cheat is false
	for (int i = 0; i < players.size() && !cheat; i++)
	{
		//if its not the current player
		if (i != currentPlayer)
		{
			cout << "Player " << i << ": ";
			//asks each player if they would like to call cheat on the
			//current bid
			cheat = players[i].callCheat(currentBid);
			//if cheat is called by a player 
			if (cheat)
			{
				cout << "Player called cheat by Player " << i + 1 << endl;
				//if player was cheating
				if (isCheat(currentBid))
				//Cheat called Correctly
				{
					//current player has to pick up the discarded cards
					players[currentPlayer].addHand(discards);
					cout << "Player cheats!" << endl;

					//might have to check this line
					cout << "Adding cards to player " << (currentPlayer + 1) 
						<< "\n" << players[currentPlayer].getHand() << endl;
					
					//if player wasnt cheating
				}
				else//Cheat called incorretly
				{
					cout << "Player honest" << endl;
					currentPlayer = i;
					//the player who called cheat has to pick up the cards
					players[currentPlayer].addHand(discards);
					cout << "Adding cards to player " << (currentPlayer + 1) 
						<<"\n"<< players[currentPlayer].getHand() << endl;
				}
				//creates the new bid and discards
				currentBid.setRank(Card::Rank::TWO);
				discards.hand.clear();
			}
		}
	}
	//no cheat called next players go
	if (!cheat)
	{
		cout << "No Cheat Called" << endl;
		currentPlayer = (currentPlayer + 1) % numPlayers;
	}
	return true;
}
//function the initialised the game cheat
void Game::initialise()
{
	//creates a new deck of cards and shuffles them
	Deck d;
	d.shuffleDeck();
	//initialise counter
	int count = 0;
	//deals all the cards in the deck to the players
	while (d.size()!= 0)
	{
		players[count % numPlayers].addCard(d.deal());
		count++;
	}
	//creates a dummy card of the two of clubs to check what player
	//curremtly has it so they can begint he game
	Card twoClubs(Card::Rank::TWO, Card::Suit::CLUBS);
	int counter = 0;
	// ###### fNEED TO CHANGE THIS FOR DIFFERENT TYPES OF PLAYERS #######
	for each (BasicPlayer bp in players)
	{
		Hand temp = bp.getHand();
		for each (Card c in temp.hand)
		{
			if (c == twoClubs)
				currentPlayer = counter;
		}
		counter++;
	}
	currentBid.setRank(Card::Rank::TWO);
	
}
//Core function of the game which invokes all the neccasry functions to 
//play the game
void Game::playGame()
{
	//initialise game
	initialise();

	int c = 0;
	bool finished = false;
	while (!finished)
	{
		//play a hand
		cout << "Cheat turn for PLAYER " << currentPlayer + 1 << endl;
		playTurn();
		cout << "Current Discards = \n" << discards << endl;
		c++;
		//prints out how many cards each player has left
		for (int j = 0; j < players.size(); j++)
		{
			cout << "Player " << j + 1 << " Cards left: " 
				<< players[j].cardsLeft() << endl;
		}
		cout << "\nTurn " << c << 
			" Complete. Press any key to continue or enter Q to quit\n" 
			<< endl;
		string answer;
		cin >> answer;
		//checking if the user would like to quit the game
		if (answer == "q" || answer == "Q" || answer == "quit")
		{
			cout << "test" << endl;
			finished = true;
		}
		//checking if we have a winner of the game
		if (winsGame())
		{
			cout << "---------------------------------"
				"----------------------------------------\n" << endl;
			cout << "The Winner is Player " << currentPlayer+1 << endl;
			cout << "Press Enter to Exit" << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			finished = true;
		}
		cout << "-------------------------------------"
			"------------------------------------" << endl;
	}
}
//function to check whether the player was cheating when another 
//player calls cheat
bool Game::isCheat(Bid b)
{
	//loop through each card in the bid
	for each (Card c in b.getHand().hand)
	{
		//as soon there isnt a match true is returned
		if (c.getRank() != b.getRank())
		{
			return true;
		}
	}
	//if all the cards match the player was honst so false is returned
	return false;
}
//function to check whether a player has won the gane
bool Game::winsGame()
{
	//checkng who is the currentplayer
	if (currentPlayer == 0)
	{
		int cPlayer = numPlayers;
		//if 0 cards left player has won
		if (players[cPlayer - 1].cardsLeft() == 0)
		{
			return true;
		}
		return false;
	}
	else if (players[currentPlayer-1].cardsLeft() ==0)
	{
		return true;
	}
	return false;
}
