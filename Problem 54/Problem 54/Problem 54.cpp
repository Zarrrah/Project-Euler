// https://projecteuler.net/problem=54

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int numberOfPlayers = 2;
const int numberOfRounds = 1000;

enum Suit {CLUBS, SPADES, HEARTS, DIAMONDS};

struct card 
{
	Suit suit;
	int value;
};

struct hand 
{
	card cards[5];
};

struct roundOfPoker 
{
	hand hands[numberOfPlayers];
};

struct game 
{
	roundOfPoker round[numberOfRounds];
};

void parseRound(const string &text, roundOfPoker round) 
{
	string roundStringData[10] = { "" };
	size_t start = 0;
	size_t end = 0;

	//Splits each card into it's own string to be parsed
	for(int i = 0; i < 5 * numberOfPlayers; i++)
	{
		end = text.find(' ', start);
		roundStringData[i] = text.substr(start, end - start);
		start = end + 1;
	}

	for (int i = 0; i < numberOfPlayers; i++) 
	{
		hand hand = round.hands[i];

		//parse each card
		for (int j = 0; j < 5; j++)
		{
			card currentCard = hand.cards[j];
			string cardStringData = roundStringData[(i * 5) + j];

			char args[2] =
			{
				cardStringData.at(0),
				cardStringData.at(1)
			};

			int value = 0;
			switch (args[0])
			{
			case 'T':
				value = 10;
				break;
			case 'J':
				value = 11;
				break;
			case 'Q':
				value = 12;
				break;
			case 'K':
				value = 13;
				break;
			case 'A':
				value = 14;
				break;
			default:
				value = args[0] - '0';
			}
			currentCard.value = value;

			switch (args[1])
			{
			case 'C':
				currentCard.suit = CLUBS;
				break;
			case 'D':
				currentCard.suit = DIAMONDS;
				break;
			case 'H':
				currentCard.suit = HEARTS;
				break;
			case 'S':
				currentCard.suit = SPADES;
				break;
			}
		}
	}
}

void readFile(game* pgame, string fileLocation) 
{
	string line;
	ifstream file (fileLocation);
	int lineNumber = 1;
	while (getline(file, line)) 
	{
		parseRound(line, pgame->round[lineNumber]);
		lineNumber++;
	}
}

int main()
{
	game game = game;
	int player1Wins = 0;

	readFile(&game, "./pokerHands.txt");
	cin.get();
}