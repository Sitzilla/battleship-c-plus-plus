#include "ship.h"
#include <string>
using namespace std;


class Battleship : public Ship {
	public:
		Battleship();
		string getName() { return name; }
		int getSize() { return size; }

	private:
		string name = "Battleship";
		int size = 4;

};