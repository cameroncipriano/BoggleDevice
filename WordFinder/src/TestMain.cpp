/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *      This is a Boggle Solver, the game to find words hidden within an 4 x 4 grid
 *      of randomized letters. This Boggle Solver is different from the rest of them
 *      because it not only finds the words digitally, but it also outputs directions
 *      for a device to play the game from it. The Tiles that constitute the board
 *      are special in that they have location data which translates into paths when
 *      Words are found. The words extract their paths into a PathList, which is
 *      ultimately used as the list of instructions to play the game.
 *
 */

#include <iostream>
#include <cstdbool>
#include <unordered_map>
#include <cstdlib>
#include <string>
#include <vector>

// My headers
#include "../headers/Tile.h"
#include "../headers/Board.h"
#include "../headers/Word.h"
#include "../headers/GameDictionary.h"
#include "../headers/BoggleGame.h"

using namespace std;

int main(int argc, char** argv) {


    /**************************************/
    /*            Tile Tester             */
    /**************************************/

    Tile myTile = Tile('C', 25, 5, 5, false);
    
    cout << myTile.isVisited() << endl;
    myTile.setVisited(true);
    cout << myTile.isVisited() << endl;

    cout << endl;
    cout << "Tile Testing Finished" << endl;

    /**************************************/
    /*            Board Tester            */
    /**************************************/

    cout << "Begin Board Testing" << endl;

    string boardLetters = "MANWHKTBGERSODCU";
    
    Board firstBoard = Board(4, 3, boardLetters);

    cout << firstBoard;

    cout << "Should see tile F: Tile Letter-- " << firstBoard.getTile(1, 1)->getLetter() << " with Location " << *(firstBoard.getTile(1, 1)->getLocation()) << endl;
    cout << "This is testing a NULL: getTile(6, 1)" << endl;
    if (firstBoard.getTile(6, 1) == NULL) {
        cout << "NULL TILE FOUND!";
    }
    else {
        cout << "... this was supposed to be NULL";
    }

    cout << endl << "Board Testing Finished" << endl;

    /**************************************/
    /*            Word Tester             */
    /**************************************/

    cout << "Begin Word Testing!\n" << endl;

    Word firstWord = Word();
    firstWord.addTile(firstBoard.getTile(0, 0));
    firstWord.addTile(firstBoard.getTile(1, 1));
    firstWord.addTile(firstBoard.getTile(2, 2));
    firstWord.addTile(firstBoard.getTile(3, 3));

    cout << "This is the word that was generated:  " << firstWord << endl;

    Word::Path* wordPath = firstWord.extractPath();
    if (wordPath == NULL) {
        cout << "The path is NULL!" << endl;
    }
    else {
        cout << "Path has been generated successfully!" << endl;
        firstWord.printPath(cout);
        cout << "Path:\n" << *wordPath << endl;
    }

    /**************************************/
    /*         Dictionary Tester          */
    /**************************************/
    
    GameDictionary dictTester = GameDictionary(3, 16, "/mnt/c/Users/socce/OneDrive/Lehigh University/Coding/BoggleSolver Project/WordFinder/src/filteredWords.txt");

    cout << dictTester.isValid("climbing") << endl;
    cout << dictTester.isValid("crumbled") << endl;
    cout << dictTester.isValid("man") << endl;
    cout << dictTester.isValid("scrumptus") << endl;

    unordered_map<string, bool> checker;
    string testWord = "crumbled";
    checker.insert({"climbing", true});

    if (dictTester.isValid(testWord) && checker.find(testWord) == checker.end()) {
        cout << "The word \"" << testWord << "\" has been added to the checker!" << endl;
        checker.insert({testWord, true});
    }

    cout << checker.find(testWord)->first << endl;

    /**************************************/
    /*         BoggleGame Tester          */
    /**************************************/


    boardLetters = "MANWHKTBGERSODCU";
    Board gameBoard = Board(4, 3, boardLetters);
    cout << gameBoard << endl;

    BoggleGame firstGame = BoggleGame(4, 3, "/mnt/c/Users/socce/OneDrive/Lehigh University/Coding/BoggleSolver Project/WordFinder/txtFiles/filteredWords.txt", boardLetters);    
    firstGame.solve();

    return 0;
}