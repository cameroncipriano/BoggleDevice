/* 
 * Author: Cameron Cipriano
 * Date: 12/28/2018
 * Description:
 *      
 *
 */

#ifndef GAMEDICTIONARY_H
#define GAMEDICTIONARY_H

#include <unordered_map> // HashMap Equivalent that uses chaining as its collision resolving method
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
        ifstream dictFile; // text file for the dictionary
        unordered_multimap<string, string> dict; // HashMap for the words
        void generateDict();
        bool canBeAdded(string wordToCheck);
};

#endif