#pragma once
#include "stdafx.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "BasicPlayer.h"
#include "HumanPlayer.h"
#include <iostream>
class Game
{
public:
	Game();
	~Game();
	Game(int n);
	bool playTurn();
	void initialise();
	void playGame();
	int winner();
	bool isCheat(Bid b);
	bool winsGame();

	
private:
	//change the type of players in the vector
	//Basic or Human
	vector<BasicPlayer> players;
	int numPlayers;
	const int MINPLAYERS = 5;
	int currentPlayer;
	Hand discards;
	Bid currentBid;
};

