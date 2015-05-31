#include "ship.h"
#include <string>
using namespace std;


class PatrolBoat : public Ship {
public:
	PatrolBoat();
	string getName() { return name; }
	int getSize() { return size; }

private:
	string name = "Patrol Boat";
	int size = 2;

};