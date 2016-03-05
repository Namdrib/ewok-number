#include "Board.h"

Board::Board()
{
	resetBoard();
}

// Clears the screen.
// Makes each new 'display' appear in the same position
void Board::clear()
{
	cout << "\033[2J";
	cout << "\033[0;0H" << endl;
}

// Prints the board layout and current moves
void Board::print()
{
	clear();
	
	// x axis labels
	cout << "  ";
	for (int i=1; i<COLUMNS+1; i++)
	{
		cout << i << "   ";
	} cout << endl;
	
	for (int x=0; x<ROWS; x++) 
	{
		// y axis labels
		cout << x+1 << " ";
		
		// Column separators and tokens
		for (int y=0; y<COLUMNS; y++) 
		{
			// Output a blank space if there is a zero
			if (cell_array[x][y].getValue() == 0)
				cout << " ";
			else
				cout << cell_array[x][y].getValue();
			
			// Column separator
			if (y<COLUMNS-1)
				cout << " | ";
		}
		
		// Row separators
		cout << endl << "  --";
		for (int i=1; i<COLUMNS; i++)
			cout << "----";
		cout << endl;
	}
	cout << endl;
}

// Insert a move into the 'lowest' slot in the specified column
// Also checks whether it is occupied
bool Board::update_cell(int row, int col, int tokenIn, string playerName)
{
	if (cell_array[row][col].getValue() == 0)
	{
		cell_array[row][col].setValue(tokenIn);
		cell_array[row][col].setPlayer(playerName);
	}
	else
		return false;
	
	print();
	return true;
}

// Sets the entire board to 0 (empty), then prints
void Board::resetBoard()
{
	for (int i=0; i<ROWS; i++)
		for (int j=0; j<COLUMNS; j++)
			cell_array[i][j].setValue(0);
		
	// print();
}

// Checks whether the board is full or not 
// Any instances of zero make it false
bool Board::checkFull()
{
	for (int i=0; i<ROWS; i++)
	{
		for (int j=0; j<COLUMNS; j++)
		{
			// If any of them are still empty
			if (cell_array[i][j].getValue() == 0)
				return false;
		}
	}
	return true;
}

// Look for the highest in each row/column
void Board::checkWin(Player &P1, Player &P2)
{
	// Check the rows
	Cell max;
	for (int i=0; i<ROWS; i++)
	{
		max.setValue(cell_array[i][0].getValue());
		for (int j=1; j<COLUMNS; j++)
		{
			max.setValue(getMax(max.getValue(), cell_array[i][j].getValue()));
			max.setPlayer(cell_array[i][j].getPlayer());
		}
		
		// Check for duplicate maximum on each row
		int maxCount = 0;
		for (int j=0; j<COLUMNS; j++)
		{
			if (cell_array[i][j].getValue() == max.getValue())
				maxCount++;
		}
		// cout << "maxCount for ROWS: " << maxCount << endl;
		// cout << "max for ROWS: " << max.getValue() << endl;
		// If there _are_ duplicate maximums, don't bother checking winner
		if (maxCount < 2)
		{
			string tempWinner = max.getPlayer();
			checkPlayerWinner(tempWinner, P1, P2);
		}
	}
	
	// Check the columns
	for (int i=0; i<COLUMNS; i++)
	{
		// Start on first position of each column
		max.setValue(cell_array[0][i].getValue());
		for (int j=1; j<ROWS; j++)
		{
			max.setValue(getMax(max.getValue(), cell_array[j][i].getValue()));
			max.setPlayer(cell_array[j][i].getPlayer());
		}
		
		// Check for duplicate maximum on each column
		int maxCount = 0;
		for (int j=0; j<ROWS; j++)
		{
			if (cell_array[j][i].getValue() == max.getValue())
				maxCount++;
		}
		// cout << "maxCount for COLUMNS: " << maxCount << endl;
		// cout << "max for COLUMNS: " << max.getValue() << endl;
		// If there _are_ duplicate maximums, don't bother checking winner
		if (maxCount < 2)
		{
			string tempWinner = max.getPlayer();
			checkPlayerWinner(tempWinner, P1, P2);
		}
	}
}

void Board::checkPlayerWinner(string winnerIn, Player &P1, Player &P2)
{
	if (winnerIn == "Player 1")
		P1.incrNumWins();
	else if (winnerIn == "Player 2")
		P2.incrNumWins();
}


int Board::getMax(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}