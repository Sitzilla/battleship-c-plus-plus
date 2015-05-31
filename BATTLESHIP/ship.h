#ifndef SHIP_H
#define SHIP_H
#include <string>

class Ship {

	public:
		Ship(string pName, int pSize);
		void setPosition(int** pPosition) { position = pPosition; }
		int** getPosition() { return position; }
		string getName() { return name; }
		int getSize() { return size; }

	private:
		int** position;
		string name = "Battleship";
		int size = 4;
};



#endif