#ifndef SHIP_H
#define SHIP_H

#include <iostream>;
#include <string>;


#define MAX_COORDINATES_ROW 5
#define MAX_COORDINATES_COL 2

using namespace std;

class Ship {

    public:
        Ship(string pName, int pSize);
        void setPosition(int(pPosition)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL]);
        bool inPosition(int coordinateOne, int coordinateTwo);
        bool hit();
        bool isSunk();
        string getName();
        int getSize();

    private:
        int position[MAX_COORDINATES_ROW][MAX_COORDINATES_COL];
        string name;
        int size = 0;
        int life = 0;
        bool sunk = false;
};

#endif