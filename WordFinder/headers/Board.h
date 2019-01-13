/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      The board is responsible for holding all of the game's Tiles. The board is essentially
 *      a container that allows everything to be put in one place for easy access for the main
 *      algorithm.
 *
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include <cstdbool>
#include "Tile.h"

using namespace std;

class Board {
    public:
        Board(ssize_t _size, size_t _minWordLen, string _gameLetters);
        ~Board();
        ssize_t getSize() const;
        size_t getMinLength() const;
        Tile* getTile(ssize_t row, ssize_t col);
        bool withinBounds(ssize_t row, ssize_t col);
        friend ostream &operator<<(ostream &out, const Board &gameBoard);
    private:
        ssize_t size;
        size_t minWordLen;
        ssize_t maxWordLen;
        vector< vector<Tile*> > gameTiles;
};

#endif