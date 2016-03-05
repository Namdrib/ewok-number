#include "Game.h"

// Default constructor for Game
Game::Game()
{
	mainMenu();
	currentPlayer = &p1;
	p1.setName("Player 1");
	p2.setName("Player 2");
	
	board.print();
	
	cout << "** Instructions up above **" << endl << endl;
}

void Game::mainMenu()
{
	cout << "Welcome to the game" << endl;
	cout << "Idea goes to EwokABdevido" << endl << endl;
	
	cout << " --- Rules --- " << endl;
	cout << " - Playing field : 3x6 integer grid" << endl;
	cout << " - Two players - Each with numbers 1-9 as their tokens" << endl;
	cout << " - Each token may only be used once" << endl;
	cout << " - Win by having the highest number of each row/column" << endl;
	cout << " - Any row/column with two equally high numbers is neutralised" << endl;
	cout << " - At the end, the rows/columns are tallied up; the player with the highest 'captures' wins" << endl;
	
	cout << endl << "The two players take turns choosing a co-ordinate in which to place their chosen number, e.g. [1 3 5] will put a number 5 in the first row, third column" << endl;
	cout << "The game ends when both players have exhausted their tokens, and by extension, when the board is full";
	cout << endl << endl << endl << endl;
}

void Game::play()
{
	int rowChoice = 0;
	int colChoice = 0;
	int numChoice = 0;
	
	// Game will continue playing while the board has free slots
	while (!board.checkFull())
	{
		cout << currentPlayer->getName() << "'s turn to move" << endl;
		currentPlayer->getUnused();
		do
		{
			cout << "Enter row (1-3), column (1-6), number (1-9)" << endl;
			cin >> rowChoice >> colChoice >> numChoice;
			
			// Ensuring that all parameters are within appropriate bounds
			// before actually adding them
			while (rowChoice < 1 || rowChoice > 3)
			{
				cout << endl << "enter an appropriate row (1-3): " << endl;
				cin >> rowChoice;
			}
			while (colChoice < 1 || colChoice > 6)
			{
				cout << endl << "enter an appropriate col (1-3): " << endl;
				cin >> colChoice;
			}
			while (numChoice < 1 || numChoice > 9 || currentPlayer->numbersUsed[numChoice-1] == true)
			{
				cout << endl << "enter an appropriate num (1-9): " << endl;
				currentPlayer->getUnused();
				cin >> numChoice;
			}
			// while (currentPlayer->numbersUsed[numChoice-1] == true)
			// {
				// cout << endl << "enter an appropriate number" <<endl;
				// currentPlayer->getUnused();
				// cin >> numChoice;
			// }
			
		} while (!board.update_cell(rowChoice-1, colChoice-1, numChoice, currentPlayer->getName()));
		currentPlayer->numbersUsed[numChoice-1] = true;
		changePlayer();
		
	}
	// At the end, calculate amount of wins, and compare them
	board.checkWin(p1, p2);
	calculateWinner();
}

bool Game::validMove(int rowChoice, int colChoice, int numChoice)
{
	// if (
}

// Make the point point to another player
// to alternate turns
void Game::changePlayer()
{
	if (currentPlayer == &p1)
		currentPlayer = &p2;
	else
		currentPlayer = &p1;
}

void Game::calculateWinner()
{
	
	if (p1.getNumWins() > p2.getNumWins())
		cout <<  p1.getName() << " has won with " << p1.getNumWins() <<  " wins" << endl;
	else if (p1.getNumWins() < p2.getNumWins())
		cout <<  p2.getName() << " has won with " << p2.getNumWins() <<  " wins" << endl;
	else 
		cout << "Draw with " << p1.getNumWins() << " wins each" << endl;
}