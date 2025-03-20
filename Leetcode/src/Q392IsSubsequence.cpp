//
// Created by AIINIRII on 2025/3/20.
//


#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j;
        for (i = 0, j = 0; i < s.length() && j < t.length(); ++j) {
            if (s[i] == t[j]) {
                i++;
            }
        }
        return i == s.length();
    }
};
