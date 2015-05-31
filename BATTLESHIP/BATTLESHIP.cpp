// BATTLESHIP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "board.h"
#include "ship.h"
#include "patrolboat.h"
#include "frigate.h"
#include "submarine.h"
#include "battleship.h"
#include "aircraftcarrier.h"
#include <iostream>
#include <string>
#include <array>


using namespace std;

int** parseInputCoordinates(int &arraySize, string coordinateOne, string coordinateTwo);
void getUserCoordiantes(string &coordinateOne, string &coordinateTwo, Ship currentShip);
bool placeShipOnBoard(Board &__1Waterboard, int** shipCoordinates, int arraySize);
int stringToInt(string str);

Board::Board() {

	// Initialize the board as a 10x10 multi-dimensional array
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			board[row][col] = NO_GUESS_NO_SHIP;
		}
	}

}


Ship::Ship(string pName, int pSize) {
	name = pName;
	size = pSize;
}

// main game logic
void startGame(Board &__1Waterboard, Board &__2Waterboard, Board &__1Targetboard, Board &__2Targetboard) {
	string coordinateOne;
	string coordinateTwo;
	Ship __1PatrolBoat("Patrol Boat", 2);
	Ship __1Frigate("Frigate", 3);
	Ship __1Submarine("Submarine", 3);
	Ship __1Battleship("Battleship", 4);
	Ship __1AircraftCarrier("Aircraft Carrier", 5);
	Ship __1shipArray[5] = { __1PatrolBoat, __1Frigate, __1Submarine, __1Battleship, __1AircraftCarrier };
	Ship __2PatrolBoat("Patrol Boat", 2);
	Ship __2Frigate("Frigate", 3);
	Ship __2Submarine("Submarine", 3);
	Ship __2Battleship("Battleship", 4);
	Ship __2AircraftCarrier("Aircraft Carrier", 5);
	Ship __2shipArray[5] = { __1PatrolBoat, __1Frigate, __1Submarine, __1Battleship, __1AircraftCarrier };
	bool success;


	//for (int shipCount = 0; shipCount < 5; shipCount++) {
	//	Ship currentShip = __1shipArray[shipCount];
	//	getUserCoordiantes(coordinateOne, coordinateTwo, currentShip);

	//	int arraySize = 0;
	//	int** shipCoordinates = parseInputCoordinates(arraySize, coordinateOne, coordinateTwo);
	//	success = placeShipOnBoard(__1Waterboard, shipCoordinates, arraySize);
	//}

	// CODE FOR TESTING OTHER SHIT
		int arraySize = 0;
		int** shipCoordinates = parseInputCoordinates(arraySize, "B3", "E3");
		success = placeShipOnBoard(__1Waterboard, shipCoordinates, arraySize);

		arraySize = 0;
		shipCoordinates = parseInputCoordinates(arraySize, "F5", "F6");
		success = placeShipOnBoard(__2Waterboard, shipCoordinates, arraySize);
		
	__1Waterboard.drawBoard();
//	__2Waterboard.drawBoard();
	exit(0);






/*
	for (int i = 0; i < arraySize; i++) {
		cout << "Coordinate " << i << ": " << shipCoordinates[i][0] << ", " << shipCoordinates[i][1] << ".\n";
	}*/

}

void launchMissle(Board &Waterboard, Board Targetboard) {
	string fireCoordinates;
	string row;
	string col;

	cout << "Please select coordinates to fire.\n";
	//NEED TO ADD CHECK HERE
	cin >> fireCoordinates;


	row = fireCoordinates.substr(0, 1);
	col = fireCoordinates.substr(1, 2);

	int row1 = stringToInt(row);  //NEED TO FIGURE OUT ASCII CONVERSIONS
	int col1 = atoi(col.c_str()) - 1; // subtract one because arrays count from 0

	if (Waterboard.hasShip(row1, col1)) {
		Waterboard.setStatus(row1, col1, 3);
	}
	else {
		Waterboard.setStatus(row1, col1, 2);
	}

}


// takes the coordinates for a ship and places it on the board
// does appropriate checks for other ships
bool placeShipOnBoard(Board &__1Waterboard, int** shipCoordinates, int arraySize) {

	for (int i = 0; i < arraySize; i++) {
		if (__1Waterboard.hasShip(shipCoordinates[i][0], shipCoordinates[i][1]) == true) {
			return false;
		}
	}
	//NEED TO SET OUT OF BOUNDS CHECK HERE (OR EARLIER)

	for (int i = 0; i < arraySize; i++) {
		__1Waterboard.setShip(shipCoordinates[i][0], shipCoordinates[i][1]);
	}

	return true;
}

int** parseInputCoordinates(int &arraySize, string coordinateOne, string coordinateTwo) {
	int **shipCoordinates = new int*[2];
	
	string row;
	string col;

	row = coordinateOne.substr(0, 1);
	col = coordinateOne.substr(1, 2);

	int row1 = stringToInt(row);  //NEED TO FIGURE OUT ASCII CONVERSIONS
	int col1 = atoi(col.c_str()) - 1; // subtract one because arrays count from 0

	// array of first set of coordinates
	shipCoordinates[0] = new int[2];
	shipCoordinates[0][0] = row1;
	shipCoordinates[0][1] = col1;
	arraySize++;

	row = coordinateTwo.substr(0, 1);
	col = coordinateTwo.substr(1, 2);

	int row2 = stringToInt(row);
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
void getUserCoordiantes(string &coordinateOne, string &coordinateTwo, Ship currentShip) {
	// NEED TO MAKE THIS NON-SHIP SPECIFIC
	cout << "Time to set your " << currentShip.getName() << "!\n";
	cout << "The " << currentShip.getName() << " is " << currentShip.getSize() << " spaces long. Please enter in first end coordinate(ex.A6).\n";
	//NEED TO ADD CHECK HERE
	cin >> coordinateOne;
	cout << "You entered " << coordinateOne << ". Please enter in the second end coordinate (ex. A9).\n ";
	//NEED TO ADD CHECK HERE
	cin >> coordinateTwo;
	cout << "Your " << currentShip.getName() << " is at coordinates " << coordinateOne << ", " << coordinateTwo << ".\n";
}

int main()
{
	Board __1Waterboard;
	Board __2Waterboard;
	Board __1Targetboard;
	Board __2Targetboard;

	startGame(__1Waterboard, __2Waterboard, __1Targetboard, __2Targetboard);

	return 0;
}

int stringToInt(string str) {
	if (str == "A") {
		return 0;
	}
	else if (str == "B") {
		return 1;
	}
	else if (str == "C") {
		return 2;
	}
	else if (str == "D") {
		return 3;
	}
	else if (str == "E") {
		return 4;
	}
	else if (str == "F") {
		return 5;
	}
	else if (str == "G") {
		return 6;
	}
	else if (str == "H") {
		return 7;
	}
	else if (str == "I") {
		return 8;
	}
	else if (str == "J") {
		return 9;
	}
	return 0;
}