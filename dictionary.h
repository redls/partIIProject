#include <unordered_map>
#include<cstdio>

using namespace std;
class Dictionary {
    private:
    unordered_map<string, long long> dictionary;

    public:
    Dictionary();
    long long retrievePhraseIndex(string phrase);

};
