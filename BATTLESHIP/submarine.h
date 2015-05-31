#include "ship.h"
#include <string>
using namespace std;


class Submarine : public Ship {
public:
	Submarine();
	string getName() { return name; }
	int getSize() { return size; }

private:
	string name = "Submarine";
	int size = 3;

};