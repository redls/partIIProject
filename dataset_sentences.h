#include <unordered_map>
#include<cstdio>

using namespace std;

/*
 * Map which keeps the reads from the "DatasetSentences.txt" stores only the sentences used for training
 * and their index.  One can find which senteces are used for testing by looking in datasetSplit.txt and
 * retrieve the sentences annotated with 1.
 */


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
};
