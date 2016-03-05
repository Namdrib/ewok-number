#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player();
	Player(string nameIn); 
	
	void setName(string nameIn);
	
	string getName();
	
	void resetMoves();
	
	bool allUsed();
	void getUnused();
	bool numbersUsed[9];
	
	void incrNumWins();
	int getNumWins();

private:
	string name;
	int numWins;
};

#endif //	PLAYER_H