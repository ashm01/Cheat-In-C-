// Cheat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "BasicPlayer.h"
#include "Game.h"
#include <iostream>


using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	
	
	


	cout << "This is CHEAT!" << endl;
	//Card cardOne(Card::Rank::KING, Card::Suit::HEARTS);
	//Card cardTwo(Card::Rank::ACE, Card::Suit::HEARTS);
	//Card cardThree(Card::Rank::QUEEN, Card::Suit::HEARTS);
	//Card cardFour(Card::Rank::KING, Card::Suit::CLUBS);
	//Card cardFive(Card::Rank::ACE, Card::Suit::CLUBS);
	//Card cardSix(Card::Rank::QUEEN, Card::Suit::CLUBS);
	///*bool answer = cardOne <= cardThree;
	//cout <<answer<<endl;
	//int cardValue = cardOne;
	//cout << cardValue << endl;
	//Deck d;
	//cout << d;;*/
	//
	///*Card card4 = d.deal();
	//Card card5 = d.deal();
	//Card card6 = d.deal();*/
	///*d.shuffleDeck();
	//cout << d;*/

	//Hand hand1;
	//hand1.add(cardOne);
	//hand1.add(cardTwo);
	//hand1.add(cardThree);
	//Hand hand2;
	//hand2.add(cardFour);
	//hand2.add(cardFive);
	//hand2.add(cardSix);
	//cout << hand1 << endl;
	////hand.remove(hand);
	//hand1.sortDescending();
	//cout << hand1 << endl;
	//cout << hand1.isFlush() << endl;
	//cout << hand1.isStraight() << endl;

	//Hand hand3;
	//hand3 = hand1 + hand2;
	//cout << hand3 << endl;
	////cout << card5.getRank() << endl;

	//BasicPlayer b;
	//b.addHand(hand3);
	//cout<< b.cardsLeft();

	//creates the game with 5 players
	Game cheat(5);
	//plays the game
	cheat.playGame();
	//command to keep the console from closing
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}

