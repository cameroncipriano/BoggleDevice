/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *      
 *
 */

#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>
#include <iostream>

// My headers
#include "Tile.h"

using namespace std;

class Word {
    public:
        class Path {
            friend class Word;
            public:
                Path();
                Path(Word::Path* oldPath);
                ~Path();
                friend ostream &operator<<(ostream &out, const Word::Path &wordPath);
            private:
                vector<Tile::Location*> locations;
        };
        Word();
        Word(Word* oldWord);
        ~Word();
        string getText() const;
        Word::Path* extractPath() const;
        size_t length() const;
        vector<Tile*> getTiles();
        void printPath(ostream &out);
        void addTile(Tile* tileToAdd);
        void removeLast();
        friend ostream &operator<<(ostream &out, const Word &word);
    private:
        string text;
        vector<Tile*> tiles;
        Path* textPath;
};

#endif