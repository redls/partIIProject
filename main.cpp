#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
#include "dictionary.h"
#include "dataset_sentences.h"

using namespace std;

int main() {
    ifstream input("testReading.txt");
    string line;
    DatasetSentences *x = new DatasetSentences();

    while(getline( input, line ) ) {
         int n = line.length();
         string word = "";
         for(char & c : line) {
            if (c == ' ') {
                cout<<word<<'\n';
                word.clear();
            } else {
                word +=c;
            }
         }
        cout<<n<<'\n';
    }
    return 0;
}
