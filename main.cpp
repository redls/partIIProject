#include <iostream>
#include<fstream>
#include<cstdio>

using namespace std;

int main()
{
    ifstream input("testReading.txt");
    string line;
    while(getline( input, line ) ) {
         cout<<line<<'\n';
    }
    return 0;
}
