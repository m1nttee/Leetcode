//
// Created by AIINIRII on 2025/3/20.
//


#include <algorithm>
#include <iostream>
#include <ostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        char nowChar = chars[0];
        int nowCharCount = 0;
        vector<char> result;
        for (auto charItem: chars) {
            if (charItem == nowChar) {
                nowCharCount++;
                continue;
            }

            result.push_back(nowChar);
            if (nowCharCount > 1) {
                while (nowCharCount >= 10) {
                    result.push_back(nowCharCount / 10 + '0');
                    nowCharCount %= 10;
                }
                result.push_back(nowCharCount + '0');
            }

            nowChar = charItem;
            nowCharCount = 1;
        }

        result.push_back(nowChar);
        if (nowCharCount > 1) {
            vector<int> nums;
            while (nowCharCount > 0) {
                nums.push_back(nowCharCount % 10);
                nowCharCount /= 10;
            }

            ranges::reverse(nums.begin(), nums.end());
            for (auto num: nums) {
                result.push_back(num + '0');
            }
        }

        for (int i = 0; i < result.size(); ++i) {
            chars[i] = result[i];
        }

        return result.size();
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<char> a = vector<char>{'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'};
    cout << s.compress(a) << endl;
    for_each(begin(a), end(a), [](char &c) { std::cout << c << ", "; });
}
