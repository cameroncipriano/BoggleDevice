/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

// My headers
#include "../headers/Tile.h"
#include "../headers/Word.h"

/**************************************/
/*           Word Specific            */
/**************************************/

Word::Word() {
    text = "";
    textPath = new Word::Path();
}

Word::Word(Word* oldWord) {
    text = oldWord->text;
    tiles = oldWord->tiles;
    textPath = oldWord->textPath;
}

Word::~Word() {
    textPath = NULL;
}

string Word::getText() const {
    return text;
}

Word::Path* Word::extractPath() const {
    return textPath;
}

size_t Word::length() const {
    return text.length();
}

vector<Tile*> Word::getTiles() {
    return tiles;
}

void Word::addTile(Tile* tileToAdd) {
    tiles.push_back(tileToAdd);
    text.push_back(tileToAdd->getLetter());
    textPath->locations.push_back(tileToAdd->getLocation());
}

void Word::removeLast() {
    tiles.pop_back();
    text.pop_back();
    textPath->locations.pop_back();
}

void Word::printPath(ostream &out) {
    ssize_t maxBoundary = textPath->locations.at(0)->col; // arbitrary as it will change
    ssize_t locsSize = textPath->locations.size();

    // finding max row and col to recreate a makeshift board
    for (ssize_t i = 0; i < locsSize; i ++) {
        Tile::Location* currLoc = textPath->locations.at(i);
        if (currLoc->row > maxBoundary) {
            maxBoundary = currLoc->row;
        }
        if (currLoc->col > maxBoundary) {
            maxBoundary = currLoc->col;
        }
    }

    bool exists = false;
    for (ssize_t row = 0; row <= maxBoundary; row++) {
        for (ssize_t col = 0; col <= maxBoundary; col++) {
            for(ssize_t tile = 0; tile < locsSize; tile++) {
                Tile::Location* currLoc = textPath->locations.at(tile);
                if (currLoc->row == row && currLoc->col == col) {
                    out << tiles.at(tile)->getLetter();
                    exists = true;
                }
            }
            if (!exists) {
                out << "   ";
            }
            exists = false;
        }
        cout << endl;
    }
}

/**************************************/
/*           Path Specific            */
/**************************************/
Word::Path::Path() {}

Word::Path::Path(Word::Path* oldPath) {
    locations = oldPath->locations;
}

Word::Path::~Path() {}

/**************************************/
/*      Printing Word and Path        */
/**************************************/

ostream &operator<<(ostream &out, const Word &word) {
    out << word.text;
    return out;
}

ostream &operator<<(ostream &out, const Word::Path &wordPath) {
    size_t pathSize = wordPath.locations.size();
    for (size_t i = 0; i < pathSize; i++) {
        out << *(wordPath.locations.at(i));
        if (i < pathSize - 1) {
            out << " -> "; 
        }
    }
    out << endl;
    return out;
}
