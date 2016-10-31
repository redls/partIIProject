#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
#include "dictionary.h"

using namespace std;

int main() {
    ifstream input("testReading.txt");
    string line;
    Dictionary *x = new Dictionary();
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
