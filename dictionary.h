#include <unordered_map>
#include<cstdio>

using namespace std;
class Dictionary {
    private:
    unordered_map<string, long> dictionary;

    public:
    Dictionary();
    long retrievePhraseIndex(string phrase);

};
