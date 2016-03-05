#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

using namespace std;

class Cell
{
public:
	void setValue(int valueIn);
	int getValue();
	
	void setPlayer(string playerIn);
	string getPlayer();
	
private:
	// The value to be used for the game (should always be between 1-9 (inclusive))
	int value;
	
	// To identify who placed the number
	// Will be retrieved from player.getName()
	string player;
};

#endif //	CELL_H