//
// Created by AIINIRII on 2025/3/19.
//


#include <algorithm>
#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int wordStart = -1;
        int wordEnd = -1;
        for (int i = 0; i < s.length(); ++i) {
            // find first char, record wordStart
            if (s[i] != ' ' && wordStart == -1) {
                wordStart = i;
                // begin to find another wordEnd
                wordEnd = -1;
            }
            // when it's the first space
            if (s[i] == ' ' && wordStart != -1 && wordEnd == -1) {
                wordEnd = i - 1;
                // 对这个单词进行 reverse 处理
                int wordBegin = wordStart;
                int wordTail = wordEnd;
                while (wordBegin < wordTail) {
                    swap(s[wordBegin++], s[wordTail--]);
                }

                // make wordStart = -1 to find next not space
                wordStart = -1;
            }
        }

        if (wordStart != -1) {
            // means there are another word need to be reverse;
            wordEnd = s.length() - 1;
            // 对这个单词进行 reverse 处理
            int wordBegin = wordStart;
            int wordTail = wordEnd;
            while (wordBegin < wordTail) {
                swap(s[wordBegin++], s[wordTail--]);
            }
        }


        // now we have a string with all words reversed, all we need now is to reverse the string and strip the space
        // 1. make the string align to the head first
        int insertIndex = 0;
        for (int i = 0; i < s.length(); ++i) {
            // append all the char to the insertIndex Pos
            if (s[i] != ' ') {
                s[insertIndex++] = s[i];
            }

            // only append the space behind the word
            if (i > 0 && s[i] == ' ' && s[i - 1] != ' ') {
                s[insertIndex++] = s[i];
            }
        }

        if (insertIndex > 0 && s[insertIndex - 1] == ' ') {
            insertIndex--;
        }

        s.resize(insertIndex);

        // 2. reverse s
        ranges::reverse(s);

        return s;
    }
};

// int main(int argc, char *argv[]) {
//     Solution s;
//     std::cout << s.reverseWords("  hello   world  ") << std::endl;
// }
