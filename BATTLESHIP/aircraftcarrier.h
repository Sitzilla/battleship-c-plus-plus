#include "ship.h"
#include <string>
using namespace std;


class AircraftCarrier : public Ship {
public:
	AircraftCarrier();
	string getName() { return name; }
	int getSize() { return size; }

private:
	string name = "Aircraft Carrier";
	int size = 5;

};