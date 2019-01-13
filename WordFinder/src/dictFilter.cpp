/* 
 * Author: Cameron Cipriano
 * Date: 1/12/2019
 * Description:
 *      This is a secondary file that simply filters a given text file by making each word lowercase and removing
 *      any words that have some form of punctuation/number in them being that these are not possible.
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    ifstream dictFilter;
    ofstream filteredDict;

    char* dictPath = argv[1];
    
    cout << dictPath << endl;
    
    dictFilter.open(dictPath, ios::in);
    filteredDict.open("/mnt/c/Users/socce/OneDrive/Lehigh University/Coding/BoggleSolver Project/WordFinder/src/filteredWords.txt", ios::out);
    
    if (!dictFilter.is_open()) {
        cerr << "Cannot open this dictionary text file. Exiting..." << endl;
        exit(1);
    }
    if (!filteredDict.is_open()) {
        cerr << "Cannot open the new text file. Exiting..." << endl;
        exit(2);
    }
    
    string currWord;
    while(getline(dictFilter, currWord)) {
        // for each word:
        //      lowercase each character
        //      if contains periods, dashes, and apostrophes, don't add it
        size_t currWordLen = currWord.length();
        bool add = true;

        // make everything lowercase
        for (size_t i = 0; i < currWordLen; i++) {
            char currChar = currWord.at(i);
            if (isupper(currChar)) {
                currWord.at(i) = tolower(currChar);
            }
            else if (ispunct(currChar) || isdigit(currChar)) {
                add = false;
                break;
            }
        }
        if (add) {
            filteredDict << currWord << endl;
        }
        add = true;
    }
    
    return 0;
}