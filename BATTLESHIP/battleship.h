#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "stdafx.h"
#include "board.h"
#include "ship.h"
#include <iostream>
#include <string>

#define MAX_COORDINATES_ROW 5
#define MAX_COORDINATES_COL 2

using namespace std;

class Battleship {

public:
    Battleship();
    bool parseInputCoordinates(int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], int &arraySize, int shipSize, string coordinateOne, string coordinateTwo);
    void getUserCoordiantes(string &coordinateOne, string &coordinateTwo, Ship currentShip);
    void placeShipOnBoard(Board &waterboard, int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], int arraySize);
    bool launchMissile(Board &ownWaterboard, Board &enemyWaterboard, Board &Targetboard, Ship shipArray[5], string player);
    void clearScreen();
    bool checkVictory(Ship shipArray[5]);
    int upperOrLower(string letter);
    bool mapInput(string inputCoordinates, int &returnRow, int &returnCol);
    bool withinBounds(int value);
    bool acceptableInput(string row, int col);
    void fillInCoordinates(int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], int &arraySize, int fixedAxis, int changeAxis1, int changeAxis2);
    bool shipAlreadyExists(Board &waterboardOne, int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], int arraySize);
    void playerShipPlacement(Board &waterboard, int(&shipCoordinates)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL], Ship shipArray[5], string player);
    bool takeTurnsFiring(Board &ownWaterboard, Board &enemyWaterboard, Board &targetboard, Ship enemyShips[5], string player);
};

#endif