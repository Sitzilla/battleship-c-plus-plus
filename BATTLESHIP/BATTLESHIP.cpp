// BATTLESHIP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "board.h"
#include "ship.h"
#include <iostream>
#include <string>
#include <array>
#include <windows.h>

#define MAX_COORDINATES_ROW 5
#define MAX_COORDINATES_COL 2

using namespace std;

bool parseInputCoordinates(int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], int &arraySize, string coordinateOne, string coordinateTwo);
void getUserCoordiantes(string &coordinateOne, string &coordinateTwo, Ship currentShip);
bool placeShipOnBoard(Board &__1Waterboard, int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], int arraySize);
void launchMissle(Board &Waterboard, Board &Targetboard, Ship shipArray[5]);
void clearScreen();
bool checkVictory(Ship shipArray[5]);
int upperOrLower(string letter);
bool mapInput(string inputRow, string inputCol, int &returnRow, int &returnCol);
bool withinBounds(int value);
bool acceptableInput(string row, int col);

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
	life = pSize;
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
	Ship __2shipArray[5] = { __2PatrolBoat, __2Frigate, __2Submarine, __2Battleship, __2AircraftCarrier };
	bool success;
	bool gameOver = false;
	int shipCoordinates[MAX_COORDINATES_ROW][MAX_COORDINATES_COL];
	memset(shipCoordinates, -1, sizeof(shipCoordinates)); //NEED TO SET IN ONE LINE


	// Ship Placement for Player one (refactor)
	for (int shipCount = 0; shipCount < 1; shipCount++) { // MAKE THIS 5
		bool acceptableInputBounds = false; // boolean to confirm user input is in bounds
		bool acceptableInputBlocked = false; // boolean to confirm user input is in empty square

		while (acceptableInputBounds == false || acceptableInputBlocked == false) {
			int arraySize = 0;
			Ship currentShip = __1shipArray[shipCount];
			getUserCoordiantes(coordinateOne, coordinateTwo, currentShip);
			acceptableInputBounds = parseInputCoordinates(shipCoordinates, arraySize, coordinateOne, coordinateTwo);
			acceptableInputBlocked = placeShipOnBoard(__1Waterboard, shipCoordinates, arraySize);
		}
		__1shipArray[shipCount].setPosition(shipCoordinates);
		memset(shipCoordinates, -1, sizeof(shipCoordinates));
	}


	// CODE FOR TESTING OTHER SHIT

		int arraySize = 0;
		parseInputCoordinates(shipCoordinates, arraySize, "F5", "F6");
		success = placeShipOnBoard(__2Waterboard, shipCoordinates, arraySize);
		__2shipArray[0].setPosition(shipCoordinates);

		while (gameOver == false) {
			cout << "    Player One - Your Ships\n";
			__1Waterboard.drawBoard();
			cout << "\n\n\n";
			launchMissle(__2Waterboard, __1Targetboard, __2shipArray);
			gameOver = checkVictory(__2shipArray);
			Sleep(1000);
			clearScreen();

			if (gameOver == true) {
				cout << "Play One has won!!!!!";
			}

			cout << "    Player Two - Your Ships\n";
			__2Waterboard.drawBoard();
			cout << "\n\n\n";
			launchMissle(__1Waterboard, __2Targetboard, __1shipArray);
			gameOver = checkVictory(__1shipArray);
			Sleep(1000);
			clearScreen();

			if (gameOver == true) {
				cout << "Play One has won!!!!!";
			}
		}

	exit(0);
}

bool checkVictory(Ship shipArray[5]) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (shipArray[i].isSunk() == true) {
			counter++;
			if (counter == 1){
				return true;
			}
		}
	}
	return false;
}

void launchMissle(Board &Waterboard, Board &Targetboard, Ship shipArray [5]) {
	string fireCoordinates;
	string row;
	string col;

	cout << "Please select coordinates to fire.\n";
	Targetboard.drawBoard();
	//NEED TO ADD CHECK HERE
	cin >> fireCoordinates;


	row = fireCoordinates.substr(0, 1);
	col = fireCoordinates.substr(1, 2);

	upperOrLower(row);

	int row1 = row.at(0) - 65;  //NEED TO FIGURE OUT ASCII CONVERSIONS
	int col1 = atoi(col.c_str()) - 1; // subtract one because arrays count from 0

	if (Waterboard.hasShip(row1, col1)) {
		Waterboard.setStatus(row1, col1, 3);
		Targetboard.setStatus(row1, col1, 3);

		for (int i = 0; i < 5; i++) {
			if (shipArray[i].inPosition(row1, col1) == true) {
				shipArray[i].hit();
				break;
			}
		}

		cout << "HIT!!!\n";
	}
	else {
		Waterboard.setStatus(row1, col1, 2);
		Targetboard.setStatus(row1, col1, 2);
		cout << "Miss\n";
	}

}

// takes the coordinates for a ship and places it on the board
// does appropriate checks for other ships
bool placeShipOnBoard(Board &__1Waterboard, int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], int arraySize) {

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

bool mapInput(string inputRow, string inputCol, int &returnRow, int &returnCol){
	string row;
	string col;

	row = inputRow.substr(0, 1);
	col = inputCol.substr(1, 2);

	int asciiSubtract = upperOrLower(row);

	returnRow = row.at(0) - asciiSubtract;
	returnCol = atoi(col.c_str()) - 1; // subtract one because arrays count from 0

	return accaptableInput(row, returnCol);
}

bool parseInputCoordinates(int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], int &arraySize, string coordinateOne, string coordinateTwo) {
	int row1, row2;
	int col1, col2;

	mapInput(coordinateOne, coordinateOne, row1, col1);
	mapInput(coordinateTwo, coordinateTwo, row2, col2);

	// array of first set of coordinates
	shipCoordinates[0][0] = row1;
	shipCoordinates[0][1] = col1;
	arraySize++;

	// array of second set of coordinates
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
			shipCoordinates[index][0] = counter;
			shipCoordinates[index][1] = col1;
			index++;
			counter++;
			arraySize++;
		}
	}
}

//checks that coordinates are in bounds and correct
bool acceptableInput(string row, int col) {
	if (upperOrLower(row) == 0) {
		return false;
	}
	else if (withinBounds(!col)) {
		return false;
	}
	return true;
}

bool withinBounds(int value){
	return (value >= 0 && value <= 10);
}

int upperOrLower(string letter) {
	if (letter >= "a" && letter <= "z") {
		return 97;
	}
	else if( letter >= "A" && letter <= "Z") {
		return 65;
	}
	return 0;
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

void clearScreen()
{
	cout << string(100, '\n');
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