#include "dictionary.h"
#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
using namespace std;

Dictionary::Dictionary() {
    ifstream input("testDictionary.txt");
    string line;
    bool is_number = false;
    long number = 0;
    string word = "";
    while(getline( input, line ) ) {
         is_number = false;
         word.clear();
         for(char & c : line) {
            if (c == '|') {
                is_number = true;
                number = 0;
            } else {
                if (!is_number) word +=c;
                else number = number*10 + c -'0';
            }
         }
         dictionary.insert(make_pair(word, number));
    }
}

long Dictionary::retrievePhraseIndex(string phrase) {
    unordered_map<string, long>::const_iterator found_iter = dictionary.find(phrase);
    if (found_iter == dictionary.end()) {
        cout<<'The given phrase: '<<phrase<<' was not found in the dictionary'<<endl;
        return -1;
        }
    return found_iter->second;
}
