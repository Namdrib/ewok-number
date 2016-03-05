#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game
{
public:
	Game();
	
	void mainMenu();
	
	void play();
	
	bool validMove(int rowChoice, int colChoice, int numChoice);

	void changePlayer();
	
	void calculateWinner();
	
// private:
	Player p1;
	Player p2;
	Player* currentPlayer;
	
	Board board;
};

#endif //	GAME_H