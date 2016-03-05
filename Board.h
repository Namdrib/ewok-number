#ifndef BOARD_H
#define BOARD_H

#define ROWS 3
#define COLUMNS 6

#include "Cell.h"
#include "Player.h"

class Board
{
public:
	Board();
	
	void clear();
	void print();
	bool update_cell(int row, int col, int tokenIn, string playerName);
	void resetBoard();
	
	bool checkFull();
	void checkWin(Player &P1, Player &P2);
	void checkPlayerWinner(string winnerIn, Player &P1, Player &P2);
	
	int getMax(int a, int b);
	
private:
	Cell cell_array[ROWS][COLUMNS];
};

#endif // BOARD_H