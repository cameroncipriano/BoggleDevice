/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *      Overrides the insertion operator for Locations so that they may be printed
 *      for testing/debugging purposes.
 *
 */

#include <cstdlib>
#include <string>
#include <cstdbool>

// My headers
#include "../headers/Tile.h"

using namespace std;

/**************************************/
/*          Tile Specific             */
/**************************************/

Tile::Tile() {
    letter = ' ';
    size = 0;
    visited = false;
    boardLoc = NULL;
}

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

char Tile::getLetter() const {
    return letter;
}

Tile::Location* Tile::getLocation() const {
    return boardLoc;
}

bool Tile::isVisited() {
    return visited;
}

void Tile::setVisited(bool status) {
    visited = status;
}

/**************************************/
/*          Tile Location             */
/**************************************/

Tile::Location::Location(ssize_t rowPos, ssize_t colPos) {
    row = rowPos;
    col = colPos;
}

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
