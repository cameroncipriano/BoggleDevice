/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *
 */

#ifndef BOGGLEGAME_H
#define BOGGLEGAME_H

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

// My headers
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