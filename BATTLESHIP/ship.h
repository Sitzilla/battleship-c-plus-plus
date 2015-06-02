#ifndef SHIP_H
#define SHIP_H
#include <string>

#define MAX_COORDINATES_ROW 5
#define MAX_COORDINATES_COL 2


class Ship {

	public:
		Ship(string pName, int pSize);

		void setPosition(int(pPosition)[MAX_COORDINATES_ROW][MAX_COORDINATES_COL]) {
			for (int row = 0; row < MAX_COORDINATES_ROW; row++) {
				for (int col = 0; col < MAX_COORDINATES_COL; col++) {
					position[row][col] = pPosition[row][col];
				}
				cout << "\n";
			}
		}

		bool inPosition(int coordinateOne, int coordinateTwo) {
			for (int row = 0; row < MAX_COORDINATES_ROW; row++) {
				if ((position[row][0] == coordinateOne) && (position[row][1] == coordinateTwo)){
					return true;
				}
			}
			return false;
		}

		void hit() {
			life--;
			if (life == 0) {
				cout << "***You sunk the enemy's " << name << "!!!\n";
				sunk = true;
			}
		}

		bool isSunk() {
			return sunk;
		}

		string getName() { return name; }
		int getSize() { return size; }

	private:
		int position[MAX_COORDINATES_ROW][MAX_COORDINATES_COL];
		string name;
		int size = 0;
		int life = 0;
		bool sunk = false;
};

#endif