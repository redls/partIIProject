/*#include "negative_words.h"
#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>

using namespace std;

NegativeWords::NegativeWords() {
    ifstream input("testDictionary.txt");
    string line;
    bool is_number = false;
    long long number = 0;
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
         negativeWordsMap.insert(make_pair(word, number));
    }
}

long long NegativeWords::getFrequency(string phrase) {
    unordered_map<string, long long>::const_iterator found_iter = negativeWordsMap.find(phrase);
    if (found_iter == negativeWordsMap.end()) {
        cout<<"The given phrase: "<<phrase<<"was not found in the dictionary"<<endl;
        return -1;
        }
    return found_iter->second;
}*/
