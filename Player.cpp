#include "Player.h"

// Set the array to all true
Player::Player()
{
	resetMoves();
	numWins = 0;
}

Player::Player(string nameIn)
{
	Player();
	setName(nameIn);
}

void Player::setName(string nameIn)
{
	name = nameIn;
}

string Player::getName()
{
	return name;
}

// Set they to fals
void Player::resetMoves()
{
	for (int i=0; i<9; i++)
	{
		numbersUsed[i] = false;
	}
}

// Output valid moves left
void Player::getUnused()
{
	// cout << "Valid moves: " << endl;
	for (int i=0; i<9; i++)
	{
		if (numbersUsed[i] == false)
			cout << i+1;
		else
			cout << "-";
		if (i < 8)
			cout << ", ";
	}
	cout << endl;
}

// See if they's all used
bool Player::allUsed()
{
	for (int i=0; i<9; i++)
	{
		if (numbersUsed[i] == false)
			return false;
	}
	return true;
}

void Player::incrNumWins()
{
	numWins++;
}

int Player::getNumWins()
{
	return numWins;
}