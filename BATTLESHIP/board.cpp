#include "stdafx.h"
#include "board.h"
#include <iostream>;
#include <string>;

using namespace std;

Board::Board() {
    // Initialize the board as a 10x10 multi-dimensional array
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            board[row][col] = NO_GUESS_NO_SHIP;
        }
    }
}

bool Board::hasShip(int row, int col) {
    if (board[row][col] == NO_GUESS_NO_SHIP) {
        return false;
    }
    return true;
}

bool Board::alreadyFired(int row, int col) {
    if (board[row][col] == HIT || board[row][col] == MISS) {
        return true;
    }
    return false;
}

void Board::setShip(int row, int col) {
    board[row][col] = NO_GUESS_SHIP;
}

void Board::drawBoard() {
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

void Board::setStatus(int row, int col, Status status) {
    board[row][col] = status;
}

int Board::getShipsRemaining() {
    return shipsRemaining;
}

void Board::sunkEnemyShip() {
    shipsRemaining--;
}

string Board::squareArt(Status content) {
    switch (content) {
    case NO_GUESS_NO_SHIP:
        return "   ";
    case NO_GUESS_SHIP:
        return " O ";
    case HIT:
        return " X ";
    case MISS:
        return " - ";
    }
}