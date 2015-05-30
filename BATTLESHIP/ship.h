#ifndef SHIP_H
#define SHIP_H

class Ship {

	public:
		Ship();
		void setPosition(int** pPosition) { position = pPosition; }
		int** getPosition() { return position; }

	private:
		int** position;
};



#endif