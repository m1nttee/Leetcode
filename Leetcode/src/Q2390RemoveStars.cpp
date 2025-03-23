//
// Created by AIINIRII on 2025/3/19.
//

#include<algorithm>
#include<random>
#include <stack>
#include<string>
#include <bits/ranges_algo.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> sStack;
        for (auto sChar: s) {
            if (sChar == '*') {
                if (!sStack.empty()) {
                    sStack.pop();
                }
            } else {
                sStack.push(sChar);
            }
        }

        string res;
        while (!sStack.empty()) {
            res += sStack.top();
            sStack.pop();
        }
        ranges::reverse(res);
        return res;
    }
};
