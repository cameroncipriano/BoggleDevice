/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      See header file
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include "../headers/Board.h"
#include "../headers/Tile.h"

using namespace std;

/**************************************/
/*          Board Specific            */
/**************************************/

/*
 * Creates the board for a BoggleGame instance
 * 
 * @param _size: The n value for an (n x n)-sized board
 * @param _minWordLen: Minimium length for a valid word
 * @param _gameLetters: string of letters that create the board
 */
Board::Board(ssize_t _size, size_t _minWordLen, string _gameLetters) {
    size = _size;
    minWordLen = _minWordLen;
    maxWordLen = _size * _size; // the maximum word length is every tile on the board (very unlikely to happen but theoretically possible)

    vector< vector<Tile*> > tempTiles(size);

    // Places each tile in the Vector gameTiles in the proper size x size grid
    size_t tileOffset = 0;
    for (ssize_t row = 0; row < size; row++) {
        for (ssize_t col = 0; col < size; col++) {
            char currLetter = _gameLetters.at(col + tileOffset);
            Tile* nextTile = new Tile(currLetter, 25, row, col, false);
            tempTiles.at(row).push_back(nextTile); 
        }
        tileOffset += size; // increases offset after each row is filled in to translate the linear vector to _size x _size grid
    }
    gameTiles = tempTiles; // copies tempTiles to gameTiles and destroys temp after this line
}

/*
 * Destroys the board by freeing the memory associated with each tile on the board
 */
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

/*
 *  @return: minimum word length for the BoggleGame instance
 */
size_t Board::getMinLength() const {
    return minWordLen;
}

/*
 *  @return: board size for the BoggleGame instance
 */
ssize_t Board::getSize() const {
    return size;
}

/*
 *  This method is to get the tile specified by the row and column on the board
 * 
 * @param row: value on the vertical axis with valid inputs of 0 (top left corner) to size (bottom left corner)
 * @param col: value on the horizontal axis with valid inputs of 0 (top left corner) to size (top right corner)
 * 
 * @return: pointer to the tile provided the row and col arguments are valid, NULL otherwise
 */
Tile* Board::getTile(ssize_t row, ssize_t col)  {
    if (withinBounds(row, col)) {
        return gameTiles.at(row).at(col);
    }
    else {
        return NULL;
    }
}

/*
 *  Tester for the row and col inputs for the getTile() method
 * 
 * @return true if 0 <= (row && col) <= size, false otherwise
 */
bool Board::withinBounds(ssize_t row, ssize_t col) {
    return ((row >= 0 && row < size) && (col >= 0 && col < size));
}

/**************************************/
/*      Printing out the Board        */
/*     in the (size x size) grid      */
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