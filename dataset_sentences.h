#include <unordered_map>
#include<cstdio>

using namespace std;
class DatasetSentences {
    private:
    unordered_map<string, long long> sentences;

    public:
    DatasetSentences();
    long long retrieveSentenceIndex(string phrase);

};
