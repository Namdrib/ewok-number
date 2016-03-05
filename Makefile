# Makefile for ewok-number game

all: main


Cell: Cell.cpp
	g++ -c Cell.cpp

Board: Cell Player Board.cpp
	g++ -c Board.cpp

Player: Player.cpp
	g++ -c Player.cpp
	
Game: Board Player Game.cpp
	g++ -c Game.cpp
	
main: Game main.cpp
	g++ -o main main.cpp Cell.o Board.o Player.o Game.o
	
clean:
	rm -f *.exe *.o *.stackdump *.core