//
// Created by AIINIRII on 2025/3/21.
//


#include<string>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowelsCount = 0, vowelsCount = 0;
        for (int i = 0; i < k; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowelsCount++;
            }
        }

        maxVowelsCount = vowelsCount;

        for (int i = k; i < s.size(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowelsCount ++;
            }
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                vowelsCount --;
            }

            if (vowelsCount > maxVowelsCount) {
                maxVowelsCount = vowelsCount;
            }

            if (vowelsCount == k) {
                return maxVowelsCount;
            }
        }
        return maxVowelsCount;
    }
};