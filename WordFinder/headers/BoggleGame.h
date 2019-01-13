/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      BoggleGame is the class that encapsulates everything needed to run the main program.
 *      This class is responsible for finding every word in the board and generating each
 *      path required for the physical device to find them.
 *
 */

#ifndef BOGGLEGAME_H
#define BOGGLEGAME_H

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include "Board.h"
#include "GameDictionary.h"
#include "Word.h"
#include "Tile.h"

class BoggleGame {
    public:
        BoggleGame(ssize_t _boardSize, size_t _minWordLen, string _dictPath, string _letters);
        ~BoggleGame();
        void solve();
        void play();
        size_t getTotalWords();
    private:
        Board* gameBoard;
        GameDictionary* gameDict;
        unordered_map<string, bool> wordChecker;
        vector<Word*> wordList;
        vector<Word::Path*> pathList;
        string pathsFile;
        size_t minWordLen;
        size_t numAnswers;
        void solveRec(Word* path, ssize_t row, ssize_t col);
};

#endif