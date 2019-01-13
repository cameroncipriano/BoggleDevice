/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include <cstdbool>

// My headers
#include "Tile.h"

using namespace std;

class Board {
    public:
        Board(ssize_t _size, size_t _minWordLen, string gameLetters);
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