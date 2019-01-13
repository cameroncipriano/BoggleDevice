/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      Word is the class and medium through which the main algorithm operates. The Word
 *      holds each Tile that represents the text, as well as the path associated with
 *      recreating the text word. The main program uses the Word to build a path, copying
 *      it once a valid word has been found.
 *
 */

#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>
#include <iostream>
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