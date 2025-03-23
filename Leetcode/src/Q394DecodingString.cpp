//
// Created by AIINIRII on 2025/3/23.
//


#include <iostream>
#include <ostream>
#include <sstream>
#include <stack>
#include<string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> multiplyStack;
        stack<string> resStack;

        int multiplierToPush = 0;
        string resToPush = "";
        for (const char c: s) {
            if ('0' <= c && c <= '9') {
                multiplierToPush *= 10;
                multiplierToPush += c - '0';
                continue;
            }

            if (c == '[') {
                multiplyStack.push(multiplierToPush);
                multiplierToPush = 0;
                resStack.push(resToPush);
                resToPush = "";
                continue;
            }

            if (c == ']') {
                auto multiplier = multiplyStack.top();
                multiplyStack.pop();
                auto res = resStack.top();
                resStack.pop();

                ostringstream resOSS;
                resOSS << res;
                while (multiplier--) {
                    resOSS << resToPush;
                }
                resToPush = resOSS.str();
                continue;
            }

            resToPush += c;
        }

        return resToPush;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
}
