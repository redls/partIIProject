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
         int n = line.length();
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
         mymap.insert(make_pair(word, number));
    }
}
