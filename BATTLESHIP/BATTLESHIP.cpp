// BATTLESHIP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "board.h"
#include "ship.h"
#include "battleship.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

int** parseInputCoordinates(int &arraySize, string coordinateOne, string coordinateTwo);
void getUserCoordiantes(string &coordinateOne, string &coordinateTwo);
bool placeShipOnBoard(Board &gameboard, int** shipCoordinates, int arraySize);

Board::Board() {

	// Initialize the board as a 10x10 multi-dimensional array
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			board[row][col] = NO_GUESS_NO_SHIP;
		}
	}

}


Ship::Ship() {

}

Battleship::Battleship() : Ship() {

}



void startGame(Board &gameboard) {
	string coordinateOne;
	string coordinateTwo;
	Battleship my_bship;
	bool success;

	int arraySize = 0;
	int** shipCoordinates = parseInputCoordinates(arraySize, "A2", "A6");

	gameboard.drawBoard();
	exit(0);

	my_bship.setPosition(shipCoordinates);

	success = placeShipOnBoard(gameboard, shipCoordinates, arraySize);

	exit(0);

	for (int i = 0; i < arraySize; i++) {
		cout << "Coordinate " << i << ": " << shipCoordinates[i][0] << ", " << shipCoordinates[i][1] << ".\n";
	}

	getUserCoordiantes(coordinateOne, coordinateTwo);

	cout << "Your Battleship is at coordinates " << coordinateOne << ", " << coordinateTwo << ".\n";
}


// takes the coordinates for a ship and places it on the board
// does appropriate checks for other ships
bool placeShipOnBoard(Board &gameboard, int** shipCoordinates, int arraySize) {

	for (int i = 0; i < arraySize; i++) {
		if (gameboard.hasShip(shipCoordinates[i][0], shipCoordinates[i][1]) == true) {
			return false;
		}
	}
	//NEED TO SET OUT OF BOUNDS CHECK HERE (OR EARLIER)

	for (int i = 0; i < arraySize; i++) {
		gameboard.setShip(shipCoordinates[i][0], shipCoordinates[i][1]);
	}

	return true;
}

int** parseInputCoordinates(int &arraySize, string coordinateOne, string coordinateTwo) {
	int **shipCoordinates = new int*[2];
	
	string row;
	string col;

	row = coordinateOne.substr(0, 1);
	col = coordinateOne.substr(1, 2);

	int row1 = atoi(row.c_str());
	int col1 = atoi(col.c_str()) - 1; // subtract one because arrays count from 0

	// array of first set of coordinates
	shipCoordinates[0] = new int[2];
	shipCoordinates[0][0] = row1;
	shipCoordinates[0][1] = col1;
	arraySize++;

	row = coordinateTwo.substr(0, 1);
	col = coordinateTwo.substr(1, 2);

	int row2 = atoi(row.c_str());
	int col2 = atoi(col.c_str()) - 1; // subtract one because arrays count from 0

	// array of second set of coordinates
	shipCoordinates[1] = new int[2];
	shipCoordinates[1][0] = row2;
	shipCoordinates[1][1] = col2;
	arraySize++;

	// if placing the ship horizontally
	if (row1 == row2) {

		// if col1 is larger than col2 then switch their values
		if (col1 > col2) {
			int old_col = col1;
			col1 = col2;
			col2 = old_col;
		}
		
		int counter = col1 + 1;
		int index = 2;

		// add in between values to array
		while (counter < col2) {
			shipCoordinates[index] = new int[2];
			shipCoordinates[index][0] = row1;
			shipCoordinates[index][1] = counter;
			index++;
			counter++;
			arraySize++;
		}
	}
	// else placing the ship vertically
	else {
		// if row1 is larger than row2 then switch their values
		if (row1 > row2) {
			int old_row = row1;
			row1 = row2;
			row2 = old_row;
		}

		int counter = row1 + 1;
		int index = 2;

		// add in between values to array
		while (counter < row2) {
			shipCoordinates[index] = new int[2];
			shipCoordinates[index][0] = counter;
			shipCoordinates[index][1] = col1;
			index++;
			counter++;
			arraySize++;
		}
	}
	return shipCoordinates;
	//delete[]array;
}


// Method to get user coordinates for ships
void getUserCoordiantes(string &coordinateOne, string &coordinateTwo) {
	// NEED TO MAKE THIS NON-SHIP SPECIFIC
	cout << "Time to set your Battleship!\n";
	cout << "The Battleship is 4 spaces long.  Please enter in first end coordinate (ex. A6).\n";
	//NEED TO ADD CHECK HERE
	cin >> coordinateOne;
	cout << "You entered " << coordinateOne << ". Please enter in the second end coordinate (ex. A9).\n ";
	//NEED TO ADD CHECK HERE
	cin >> coordinateTwo;
	cout << "Your Battleship is at coordinates " << coordinateOne << ", " << coordinateTwo << ".\n";
}

int main()
{
	Board gameboard;
//	Battleship my_bship;

	startGame(gameboard);

	return 0;
}

