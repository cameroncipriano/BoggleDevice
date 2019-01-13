/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>

// My headers
#include "../headers/Board.h"
#include "../headers/Tile.h"

using namespace std;

/**************************************/
/*          Board Specific            */
/**************************************/

Board::Board(ssize_t _size, size_t _minWordLen, string gameLetters) {
    size = _size;
    minWordLen = _minWordLen;
    maxWordLen = size * size;

    vector< vector<Tile*> > tempTiles(size);

    // Places each tile in the Vector _gameTiles in the proper size x size grid
    size_t tileOffset = 0;
    for (ssize_t row = 0; row < size; row++) {
        for (ssize_t col = 0; col < size; col++) {
            char currLetter = gameLetters.at(col + tileOffset);
            Tile* nextTile = new Tile(currLetter, 25, row, col, false);
            tempTiles.at(row).push_back(nextTile); 
        }
        tileOffset += size; // increases offset after each row is filled in
    }
    gameTiles = tempTiles; // copies tempTiles to gameTiles and destroys temp after this line
}

Board::~Board() {
    // must free the tiles that the board created
    for (ssize_t row = 0; row < size; row++) {
        for (ssize_t col = 0; col < size; col++) {
            Tile* currTile = gameTiles.at(row).at(col);
            if (currTile != NULL) {
                delete currTile;
            }
            gameTiles.at(row).at(col) = NULL;
        }
    }
}

size_t Board::getMinLength() const {
    return minWordLen;
}

ssize_t Board::getSize() const {
    return size;
}

Tile* Board::getTile(ssize_t row, ssize_t col)  {
    if (withinBounds(row, col)) {
        return gameTiles.at(row).at(col);
    }
    else {
        return NULL;
    }
}

bool Board::withinBounds(ssize_t row, ssize_t col) {
    return ((row >= 0 && row < size) && (col >= 0 && col < size));
}

/**************************************/
/*      Printing out the Board        */
/*      in the size x size grid       */
/*              fashion               */
/**************************************/

ostream &operator<<(ostream &out, const Board &gameBoard) {
    ssize_t currTile = 0;

    for (ssize_t row = 0; row < gameBoard.size; row++) {
        for (ssize_t col = 0; col < gameBoard.size; col++) {
            out << gameBoard.gameTiles.at(row).at(col)->getLetter(); // prints out each letter
            currTile++;
            if (currTile % gameBoard.size == 0) { // prints a newline when it hits the size of the board
                out << endl;
            }
            else {
                out << "  "; // spaces each letter out to see the grid easier
            }
        }
    }
    return out;
}