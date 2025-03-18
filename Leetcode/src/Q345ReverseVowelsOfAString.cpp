//
// Created by AIINIRII on 2025/3/19.
//


#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowelsIndex;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowelsIndex.push_back(i);
            }
        }

        int i = 0, j = vowelsIndex.size() - 1;
        while (i < j) {
            swap(s[vowelsIndex[i]], s[vowelsIndex[j]]);
            i += 1;
            j -= 1;
        }

        return s;
    }
};
