/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *      The Tile is the backbone for this BoggleSolver as it encapsulates all of the data needed
 *      for the main program to find words and generate paths to recreate them. The Tile has the
 *      letter and location that it represents on the board.
 *
 */

#ifndef TILE_H
#define TILE_H

#include <cstdbool>
#include <iostream>
#include <string>

using namespace std;

class Tile {
    public:
        class Location {
            friend class Board;
            friend class Path;
            public:
                Location(ssize_t rowPos, ssize_t colPos);
                Location(Tile::Location* oldLoc);
                friend ostream& operator<<(ostream &out, const Location &loc);
                ssize_t row;
                ssize_t col;
        };
        Tile();
        Tile(char _letter, size_t _size, ssize_t _boardRow, ssize_t _boardCol, bool _visited);
        ~Tile();
        bool isVisited();
        void setVisited(bool status);
        char getLetter() const;
        Location* getLocation() const;
    private:
        char letter;
        size_t size;
        bool visited;
        Location* boardLoc;
};

#endif