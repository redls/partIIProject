#include <unordered_map>
#include<cstdio>

using namespace std;

class DatasetSentences {
    private:
    unordered_map<string, long long> sentences;

    public:

    // Constructor.
    DatasetSentences();

    // Given a sentence retrieve the sentence index.
    long long retrieveSentenceIndex(string phrase);

    // Retrieve map.
    unordered_map<string, long long> getSentencesMap();

    // Return the number of positive sentences in the  dataset.
    //long long numberofPositiveSentences();

    // Return the number of negative sentences in the  dataset.
  //  long long numberofNegativeSentences();

};
