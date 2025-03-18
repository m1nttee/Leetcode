//
// Created by AIINIRII on 2025/3/18.
//

#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // initialize result string
        string resultString;

        // for loop for word1
        int word1Index = 0, word2Index = 0;
        while (word1.length() > word1Index && word2.length() > word2Index) {
            resultString += word1[word1Index];
            resultString += word2[word2Index];
            word1Index++;
            word2Index++;
        }

        // add the remain part to result string
        if (word1Index < word1.length()) {
            resultString += word1.substr(word1Index, word1.length() - word1Index);
        }

        if (word2Index < word2.length()) {
            resultString += word2.substr(word2Index, word2.length() - word2Index);
        }

        return resultString;
    }
};
