#include "sentiment_labels.h"
#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>

using namespace std;

SentimentLabels::SentimentLabels() {
    ifstream input("testSentimentLabels.txt");
    string line;
    bool character = false;
    bool first_line = true;
    long long first_number = 0;
    double second_number = 0;
    string word = "";
    while(getline( input, line ) ) {
         character = false;
         first_number = 0;
         second_number = 0;
         word.clear();
         if (!first_line) {
            for(char & c : line) {
                if (c == '|') {
                    character = true;
                } else {
                    if (!character) first_number = first_number*10 + c -'0';
                    else {
                        word +=c;
                    }
                }
            }
            second_number = atof(word.c_str());
            sentimentLabelsMap.insert(make_pair(first_number, second_number));
            cout<<first_number<<" "<<second_number<<endl;
         }
         first_line = false;
    }
}

double SentimentLabels::getSentimentScore(long long phraseIndex) {
    unordered_map<long long, double>::const_iterator found_iter = sentimentLabelsMap.find(phraseIndex);
    if (found_iter == sentimentLabelsMap.end()) {
        cout<<"The given index: "<<phraseIndex<<"was not found in the dictionary"<<endl;
        return -1;
        }
    return found_iter->second;
}
