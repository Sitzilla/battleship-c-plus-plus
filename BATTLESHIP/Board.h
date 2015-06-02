#ifndef BOARD_H
#define BOARD_H

#include <iostream>;
#include <string>;
using namespace std;

class Board {
	public:

		Board();
		bool hasShip(int row, int col) {
			if (board[row][col] == NO_GUESS_NO_SHIP) {
				return false;
			}
			return true;
		}

		bool alreadyFired(int row, int col) {
			if (board[row][col] == HIT || board[row][col] == MISS) {
				return true;
			}
			return false;
		}

		void setShip(int row, int col) {
			board[row][col] = NO_GUESS_SHIP;
		}

		void drawBoard() {
			int letter = 65;

			cout << "     1   2   3   4   5   6   7   8   9   10 \n";
			cout << "   ----------------------------------------\n";

			for (int row = 0; row < 10; row++) {
				cout << " " << static_cast<char>(letter) << " ";
				for (int col = 0; col < 10; col++) {
					cout << "|" << squareArt(board[row][col]);
				}
				cout << "|\n";
				cout << "   ----------------------------------------\n";
				letter++;
			}
		}

		void setStatus(int row, int col, int status) {
			switch (status) {
				case 0: board[row][col] = NO_GUESS_NO_SHIP;
						break;
				case 1: board[row][col] = NO_GUESS_SHIP;
						break;
				case 2: board[row][col] = MISS;
						break;
				case 3: board[row][col] = HIT;
						break;
			}
		}

	private:
		//BRING THIS OUTSIDE OF BOARD!!!!
		enum Status {
			NO_GUESS_NO_SHIP,
			NO_GUESS_SHIP,
			MISS,
			HIT,
		};
		Status board[10][10];

		string squareArt(Status content) {
			if (content == NO_GUESS_NO_SHIP){
				return "   ";
			}
			else if (content == NO_GUESS_SHIP) {
				return " O ";
			}
			else if (content == HIT) {
				return " X ";
			}
			else if (content == MISS) {
				return " - ";
			}
		}

};

#endif