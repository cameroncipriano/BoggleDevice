/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      See header file
 *
 */

#include <cstdlib>
#include <string>
#include <cstdbool>
#include "../headers/Tile.h"

using namespace std;

/**************************************/
/*          Tile Specific             */
/**************************************/

/*
 * Default configuration for a tile
 */
Tile::Tile() {
    letter = ' ';
    size = 0;
    visited = false;
    boardLoc = NULL;
}

/*
 * Creates tile with all information known
 * 
 * @param _letter: The character on the board
 * @param _size: The size of the tile in the digital game: needed for device accuracy
 * @param _boardRow: Vertical location on the board the Tile will go
 * @param _boardCol: Horizontal location on the board the Tile will go
 * @param _visisted: indicates if this tile is currently being considered for a word
 */
Tile::Tile(char _letter, size_t _size, ssize_t _boardRow, ssize_t _boardCol, bool _visited) {
    letter = tolower(_letter);
    size = _size;
    visited = _visited;
    boardLoc = new Tile::Location(_boardRow, _boardCol);
}

Tile::~Tile() {
    // must free the location that the tile created
    if (boardLoc != NULL) {
        delete boardLoc;    
    }
    boardLoc = NULL;
}

/*
 * @return: the letter associated with the current tile
 */
char Tile::getLetter() const {
    return letter;
}

/*
 * @return: pointer to the location associated with the current tile
 */
Tile::Location* Tile::getLocation() const {
    return boardLoc;
}

/*
 * @return: true if the current tile is being considered for a path
 */
bool Tile::isVisited() {
    return visited;
}

/*
 * @param status: true or false depending on if the current tile is being considered for a path
 */
void Tile::setVisited(bool status) {
    visited = status;
}

/**************************************/
/*          Tile Location             */
/**************************************/

/*
 * @param rowPos: Vertical position on the board
 * @param colPos: Horizontal position on the board
 */
Tile::Location::Location(ssize_t rowPos, ssize_t colPos) {
    row = rowPos;
    col = colPos;
}

/*
 * @param oldLoc: this is for copying purposes of creating a new tile with the same values
 */
Tile::Location::Location(Tile::Location* oldLoc) {
    row = oldLoc->row;
    col = oldLoc->col;
}

/**************************************/
/*     Testing Purpose Printing       */
/**************************************/

ostream &operator<<(ostream &out, const Tile::Location &loc) {
    out << "(" << loc.row << ", " << loc.col << ")";
    return out;
}
