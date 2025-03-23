//
// Created by AIINIRII on 2025/3/21.
//


#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int from = 0, to = 0;
        for (int i = 0; i < k && to < nums.size();) {
            if (nums[to++] == 0) {
                i++;
            }
        }

        int maxCount = to - from;

        while (to < nums.size()) {
            if (nums[to++] == 0) {
                while (nums[from++] == 1) {
                }
            }

            if (maxCount < to - from) {
                maxCount = to - from;
            }
        }
        return maxCount;
    }
};

// int main(int argc, char *argv[]) {
//     Solution s;
//     vector nums = {0, 0, 0, 1};
//     std::cout << s.longestOnes(nums, 4) << std::endl;
// }
