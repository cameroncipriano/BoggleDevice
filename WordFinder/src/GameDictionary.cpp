/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      See header file
 *
 */

#include <unordered_map>
#include <cstdbool>
#include <string>
#include <iostream>
#include <fstream>
#include "../headers/GameDictionary.h"

using namespace std;

/*
 * @param _minWordLen: Minimum word length for valid words
 * @param _maxWordLen: Maximum word length for valid words
 * @param _dictPath: String path to the dictionary text file
 */
GameDictionary::GameDictionary(size_t _minWordLen, size_t _maxWordLen, string _dictPath) {
    minWordLen = _minWordLen;
    maxWordLen = _maxWordLen;
    dictPath = _dictPath;
    generateDict(); // separate method to redeuce clutter
}

/* 
 * Filters dicitionary for words shorter than indicated minWordLen and ensures proper longest lengths
 * 
 * @param wordToCheck: input word to determine if it can be added to the game's dictionary
 */
bool GameDictionary::canBeAdded(string wordToCheck) {
    return (wordToCheck.substr(0, minWordLen).length() >= minWordLen && wordToCheck.length() <= maxWordLen);
}

/*
 * Searches the finalized dictionary for the provided word
 * 
 * @param wordToGet: string to search the dictionary for
 */
bool GameDictionary::isValid(string wordToGet) {
    string currKey = wordToGet.substr(0, minWordLen);

    unordered_map<string, string>::iterator wordIt = dict.find(currKey);
    if (wordIt == dict.end()) { // the key was not found in the dictionary, indicating it does not exist
        return false;
    }
    else {
        // because the dictionary is a HashTable, we can further improve search speeds by restricting the search to the bucket with the same key
        while(wordIt->first.compare(currKey.c_str()) == 0) {
            if (wordIt->second.compare(wordToGet.c_str()) == 0) {
                return true;
            }
            else {
                wordIt++;
            }
        }
    }
    return false; // the word was not found in its key's bucket
}

/*
 * Private method to keep constructor code manageable. The purpose is to build the HashTable
 * specifically for the game being played based on the min and max word length
 * 
 */
void GameDictionary::generateDict() {    
    dictFile.open(dictPath, ios::in); // opens dictionary text file

    // with each word, use the first *minWordLen* letters to generate the keys
    string currWord;
    if (!dictFile.is_open()) {
        cerr << "Unable to open Dictionary File... exiting." << endl;
        exit(1);
    }
    else {
        cout << "Building dictionary...\n" << endl;
        while (getline(dictFile, currWord)) {
            string currKey = currWord.substr(0, minWordLen);
            if (canBeAdded(currWord)) {
                // words at this point are sufficient to be added to the HashMap
                dict.insert({currKey, currWord});
            }
        }
        dictFile.close();
        cout << "Dictionary construction complete!\n" << endl;
    }
}