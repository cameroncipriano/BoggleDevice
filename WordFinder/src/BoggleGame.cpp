/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

// My headers
#include "../headers/BoggleGame.h"
#include "../headers/Board.h"
#include "../headers/GameDictionary.h"
#include "../headers/Word.h"
#include "../headers/Tile.h"

using namespace std;

/*
 * Default constructor simply constructs the necessary pieces to run the game
 * 
 * @param _boardSize: (# x #) This is the tile
 * @param _minWordLen: Minimum length for words used for the GameDictionary construction
 * @param _dictPath: file path to the text file of the words
 * @param _letters: container for the game's board letters
 */
BoggleGame::BoggleGame(ssize_t _boardSize, size_t _minWordLen, string _dictPath, string _letters) {
    minWordLen = _minWordLen;
    numAnswers = 0;
    gameBoard = new Board(_boardSize, _minWordLen, _letters);
    gameDict = new GameDictionary(_minWordLen, (_boardSize * _boardSize), _dictPath);
}

/*
 * Deletes the associated objects to run the game
 */
BoggleGame::~BoggleGame() {
    if (gameBoard != NULL) {
        delete gameBoard;
    }
    gameBoard = NULL;

    if (gameDict != NULL) {
        delete gameDict;
    }
    gameDict = NULL;

    // must delete the words in here because they were created as copies during the solve method
    for (size_t i = 0; i < wordList.size(); i++) {
        if (wordList.at(i) != NULL) {
            delete wordList.at(i);
        }
        wordList.at(i) = NULL;
    }

    // must delete the paths in here because they were created as copies during the solve method
    for (size_t i = 0; i < pathList.size(); i++) {
        if (pathList.at(i) != NULL) {
            delete pathList.at(i);
        }
        pathList.at(i) = NULL;
    }
}

size_t BoggleGame::getTotalWords() {
    return numAnswers;
}

/*
 * Does the heavy lifting in terms of finding the words and adding each to the final
 * word/pathList
 */
void BoggleGame::solve() {
    Word* currWordPath = new Word();
    // each tile on the board acts as a starting point for a path
    ssize_t gameBoardSize = gameBoard->getSize();
    for (ssize_t row = 0; row < gameBoardSize; row++) {
        for (ssize_t col = 0; col < gameBoardSize; col++) {
            Tile* currTile = gameBoard->getTile(row, col);
            cout << "Starting new path from Tile \"" << currTile->getLetter() << "\" at " << *(currTile->getLocation()) << "\n"; 
            solveRec(currWordPath, row, col);
        }
    }
    delete currWordPath;
    
    // print all the paths
    cout <<"\nAll possible paths:" << endl;
    for (size_t i = 0; i < pathList.size(); i++) {
        cout << *(pathList.at(i))<< "\n";
    }
    cout.flush();
    
    // print all the solutions
    cout <<"\nAll possible words:" << endl;
    for (size_t i = 0; i < wordList.size(); i++) {
        cout << wordList.at(i)->getText() << "\n";
    }
    cout.flush();
}

void BoggleGame::solveRec(Word* thisWordPath, ssize_t row, ssize_t col) {
    Tile* currTile = gameBoard->getTile(row, col);

    
    // do not need to check for null because that is done in the recursive loops at the end
    currTile->setVisited(true);
    thisWordPath->addTile(currTile);

    string currWord = thisWordPath->getText();
    if (thisWordPath->length() >= minWordLen) {
        if (gameDict->isValid(currWord) && wordChecker.find(currWord) == wordChecker.end()) {
                // total number of words found
                numAnswers++;
                
                // add a copy of the current word to the worwdList
                Word* newWord = new Word(thisWordPath);
                wordList.push_back(newWord);

                // add a copy of the current path to the pathList
                Word::Path* newPath = new Word::Path(thisWordPath->extractPath());
                pathList.push_back(newPath);

                // make sure the word cannot be added again
                wordChecker.insert({currWord, true});
        }
    }
    for (ssize_t r = -1; r <= 1; r++) {
        for (ssize_t c = -1; c <= 1; c++) {
            Tile* nextTile = gameBoard->getTile(row + r, col + c);
            if (nextTile != NULL && !(nextTile->isVisited())) {
                solveRec(thisWordPath, row + r, col + c);
            }
        }
    }
    /* 
        Once the current path is done, it will back recurse to start the new one. 
        This effectively clears the path from back to front so a new one can start
    */
    thisWordPath->removeLast();
    currTile->setVisited(false);
}

/*
 * This will be the method that plays it on the BoggleSolving Device. This takes the pathsFile
 * and will be read by the device to play the game.
 */
void BoggleGame::play() {

}