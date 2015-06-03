#ifndef BOARD_H
#define BOARD_H

#include <iostream>;
#include <string>;
using namespace std;

enum Status {
    NO_GUESS_NO_SHIP,
    NO_GUESS_SHIP,
    MISS,
    HIT,
};

class Board {
    public:
        Board();
        bool hasShip(int row, int col);
        void setShip(int row, int col);
        bool alreadyFired(int row, int col);
        void drawBoard();
        void setStatus(int row, int col, Status status);
        int getShipsRemaining();
        void sunkEnemyShip();

    private:
        int shipsRemaining = 5;
        Status board[10][10];
        string squareArt(Status content);
};

#endif