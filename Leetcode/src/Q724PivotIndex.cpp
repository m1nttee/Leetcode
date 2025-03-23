//
// Created by AIINIRII on 2025/3/21.
//


#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                leftSum += nums[i - 1];
            }
            sum -= nums[i];
            if (leftSum == sum) {
                return i;
            }
        }
        return -1;
    }
};
