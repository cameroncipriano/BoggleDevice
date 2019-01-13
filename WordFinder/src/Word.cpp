/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      See header file
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include "../headers/Tile.h"
#include "../headers/Word.h"

/**************************************/
/*           Word Specific            */
/**************************************/

/*
 * Default configuration for a word
 */
Word::Word() {
    text = "";
    textPath = new Word::Path();
}

/*
 * @param oldWord: pointer to another word that is used for copying purposes
 */
Word::Word(Word* oldWord) {
    text = oldWord->text;
    tiles = oldWord->tiles;
    textPath = oldWord->textPath;
}

Word::~Word() {
    textPath = NULL;
}

/*
 * @return: the string representation of the current word
 */
string Word::getText() const {
    return text;
}

/*
 * @return: pointer to the current Word's path
 */
Word::Path* Word::extractPath() const {
    return textPath;
}

/*
 * @return: the length of the text associated with the current word
 */
size_t Word::length() const {
    return text.length();
}

/*
 * @param tileToAdd: pointer to the Tile that needs to be associated with the current Word
 */
void Word::addTile(Tile* tileToAdd) {
    tiles.push_back(tileToAdd);
    text.push_back(tileToAdd->getLetter());
    textPath->locations.push_back(tileToAdd->getLocation());
}

/*
 * Removes the last element from each of the Word's members for use in clearing
 */
void Word::removeLast() {
    tiles.pop_back();
    text.pop_back();
    textPath->locations.pop_back();
}

/*
 * This is to print out a representation of the word in its grid form
 * 
 * @param out: stream to print the path to.
 */
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

    // this piece prints the board with only the word's letters in their respective locations
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

/*
 * @param oldPath: Another word that is used for copying during the main algorithm
 */
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
    for (size_t i = 0; i < pathSize; i++) { // prints out each location in the form "(row, col) -> (row, col)"
        out << *(wordPath.locations.at(i));
        if (i < pathSize - 1) {
            out << " -> ";
        }
    }
    out << endl;
    return out;
}
