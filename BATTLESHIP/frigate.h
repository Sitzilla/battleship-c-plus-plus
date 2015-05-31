#include "ship.h"
#include <string>
using namespace std;


class Frigate : public Ship {
public:
	Frigate();
	string getName() { return name; }
	int getSize() { return size; }

private:
	string name = "Frigate";
	int size = 3;

};