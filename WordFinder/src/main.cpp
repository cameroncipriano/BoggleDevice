/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *
 */

#include <cstdlib>
#include <string>
#include <iostream>

// My headers 
#include "../headers/BoggleGame.h"

int main(int argc, char** argv) {
    
    // for an instance of the BoggleGame, we need the board size, minWordLen, and the letters
    size_t boardSize = 0;
    size_t propNumLetters = 0;
    size_t numLetters;
    size_t minWordLen = 0;
    string boardLetters;
    string dictPath;

    switch(argc) {
        case 1:
            cerr << "\nNot enough arguments!" << endl;
            cerr << "<filename> <dictFile> <boardSize> <minWordLen> <letters...>\n" << endl;
            exit(1);
        case 2:
            cerr << "\nNot enough arguments!" << endl;
            cerr << "Please enter a path to a valid dictionary text file." << endl;
            cerr << "<filename> <dictFile> <boardSize> <minWordLen> <letters...>\n" << endl;
            exit(2);
        case 3:
            cerr << "\nNot enough arguments!" << endl;
            cerr << "Please enter a minimium word length and then the associated board letters!" << endl;
            cerr << "<filename> <dictFile> <boardSize> <minWordLen> <letters...>\n" << endl;
            exit(3);
        case 4:
            boardSize = stoi(argv[2]);
            propNumLetters = (int)(boardSize * boardSize);
            cerr << "\nNot enough arguments!" << endl;
            cerr << "Please type in the board letters! Based on your input, you need ";
            cerr << propNumLetters << endl;
            cerr << "<filename> <dictFile> <boardSize> <minWordLen> <letters...>\n" << endl;
            exit(4);            
        default:
            dictPath = argv[1];
            boardSize = stoul(argv[2]);
            propNumLetters = (int)(boardSize * boardSize);
            minWordLen = stoul(argv[3]);
            boardLetters = argv[4];
            numLetters = boardLetters.length();

            if (numLetters != propNumLetters) {
                cerr << "\nNot enough letters!" << endl;
                cerr << "You entered " << numLetters << " but you still need " << (propNumLetters - numLetters) << " more!\n" << endl;
                exit (5);
            }
            else {
                // capitalize the word if it isn't
                for (size_t i = 0; i < numLetters; i++) {
                    boardLetters.at(i) = toupper(boardLetters.at(i));
                }
            }
            break;
    }

    cout << "\n\nEntered Dictionary Path: " << dictPath << endl;
    cout << "Entered boardSize: " << boardSize << endl;
    cout << "Entered minWordLen: " << minWordLen << endl;
    cout << "Entered letters:" << endl;
    for (size_t i = 0; i < boardLetters.length(); i++) {
        cout << boardLetters.at(i) << " ";
    }
    cout << "\n\n" << endl ;

    BoggleGame game = BoggleGame(boardSize, minWordLen, dictPath, boardLetters);
    game.solve();

    return 0;
}