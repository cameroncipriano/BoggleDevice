/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      The GameDictionary is responsible for constructing the dictionary to be used in
 *      validating the words found by the BoggleGame class. This class performs the function
 *      of placing each valid word provided by a text file in a HashMap's bucket based on a
 *      key determined by the minimum word length.
 *
 */

#ifndef GAMEDICTIONARY_H
#define GAMEDICTIONARY_H

#include <unordered_map>
#include <string>
#include <cstdbool>
#include <iostream>
#include <fstream>

using namespace std;

class GameDictionary {
    public:
        GameDictionary(size_t _minWordLen, size_t _maxWordLen, string _dictPath);
        bool isValid(string wordToCheck);
    private:
        size_t minWordLen;
        size_t maxWordLen;
        string dictPath;
        ifstream dictFile;
        unordered_multimap<string, string> dict;
        void generateDict();
        bool canBeAdded(string wordToCheck);
};

#endif