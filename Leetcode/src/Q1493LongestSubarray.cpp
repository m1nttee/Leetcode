//
// Created by AIINIRII on 2025/3/21.
//


#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int from = 0, to = 0;
        for (int i = 0; i < 1 && to < nums.size();) {
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

        return maxCount - 1;
    }
};