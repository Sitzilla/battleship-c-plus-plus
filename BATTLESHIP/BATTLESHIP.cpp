// BATTLESHIP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "board.h"
#include <iostream>
using namespace std;

Board::Board(){

	// Initialize the board as a 10x10 multi-dimensional array
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			board[row][col] = false;
		}
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	Board gameboard;

	return 0;
}

