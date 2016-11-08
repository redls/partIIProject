#include "dataset_sentences.h"
#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
using namespace std;

DatasetSentences::DatasetSentences() {
    ifstream input("testDictionary.txt");
    string line;
    bool is_number = false;
    long long number = 0;
    string word = "";
    while(getline( input, line ) ) {
         is_number = true;
         number = 0;
         word.clear();
         for(char & c : line) {
            if (c == '\t') {
                is_number = false;

            } else {
                if (!is_number) word +=c;
                else number = number*10 + c -'0';
            }
         }
         sentences.insert(make_pair(word, number));
         cout<<number<<word<<endl;
    }
}

long long DatasetSentences::retrieveSentenceIndex(string phrase) {
    unordered_map<string, long long>::const_iterator found_iter = sentences.find(phrase);
    if (found_iter == sentences.end()) {
        cout<<"The given phrase: "<<phrase<<"was not found in the sentence dataset."<<endl;
        return -1;
        }
    return found_iter->second;
}
