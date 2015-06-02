#include "stdafx.h"
#include "ship.h"
#include <iostream>;
#include <string>;

#define MAX_COORDINATES_ROW 5
#define MAX_COORDINATES_COL 2

using namespace std;



Ship::Ship(string pName, int pSize) {
    name = pName;
    size = pSize;
    life = pSize;
}

void Ship::setPosition(int(pPosition)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL]) {
    for (int row = 0; row < MAX_COORDINATES_ROW; row++) {
        for (int col = 0; col < MAX_COORDINATES_COL; col++) {
            position[row][col] = pPosition[row][col];
        }
        cout << "\n";
    }
}

bool Ship::inPosition(int coordinateOne, int coordinateTwo) {
    for (int row = 0; row < MAX_COORDINATES_ROW; row++) {
        if ((position[row][0] == coordinateOne) && (position[row][1] == coordinateTwo)){
            return true;
        }
    }
    return false;
}

// Simulates a ship being hit. Returns true if ship is sunk
bool Ship::hit() {
    life--;
    if (life == 0) {
        cout << "***You sunk the enemy's " << name << "!!!\n";
        sunk = true;
        return true;
    }
    return false;
}

bool Ship::isSunk() {
    return sunk;
}

string Ship::getName() {
    return name;

}

int Ship::getSize() {
    return size;
}