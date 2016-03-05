#include "Cell.h"

// Getter/setter functions for value
void Cell::setValue(int valueIn)
{
	value = valueIn;
}

int Cell::getValue()
{
	return value;
}


// Getter/setter functions for player
void Cell::setPlayer(string playerIn)
{
	player = playerIn;
}

string Cell::getPlayer()
{
	return player;
}