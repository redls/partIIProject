#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
#include "dictionary.h"
#include "dataset_sentences.h"
#include "sentiment_labels.h"

using namespace std;

void updateFrequencyOfWord(unordered_map<string, long long> *mapp, string word) {
    unordered_map<string, long long>::const_iterator found_iter = mapp->find(word);
    if (found_iter == mapp->end()) {
        mapp->insert(make_pair(word, 1));
        return;
        }
    long long value = found_iter->second;
     mapp->insert(make_pair(word, value + 1));
}

int main() {
    ifstream input("testReading.txt");
    string line;

    long long positiveSentences = 0;
    long long negativeSentences = 0;
    bool is_positive = true;
    SentimentLabels *sentimentLabels = new SentimentLabels();
    DatasetSentences *datasetSentences = new DatasetSentences();
    Dictionary *dictionary = new Dictionary();
    unordered_map<string, long long> sentences = datasetSentences->getSentencesMap();
    unordered_map<string, long long> positiveWordsMap;
    unordered_map<string, long long> negativeWordsMap;

    for (auto it = sentences.begin(); it != sentences.end(); ++it ) {
        string sentence = it->first;
        long long phraseIndex = dictionary->getPhraseIndex(sentence);
        if (phraseIndex >= 0) {
            double sentimentScore = sentimentLabels->getSentimentScore(phraseIndex);
            if (sentimentScore >= 0) {
                if (sentimentScore >= 0.5) positiveSentences++;
                else {
                    negativeSentences++;
                    is_positive = false;
                }
                string word = "";
                for(char & c : sentence) {
                    if (c == ' ') {
                        if (is_positive) {
                            updateFrequencyOfWord(&positiveWordsMap, word);
                        } else {
                            updateFrequencyOfWord(&negativeWordsMap, word);
                        }
                        word.clear();
                    } else {
                        word = word + c;
                    }
                }
            }
        }
    }

    return 0;
}
