//
// Created by AIINIRII on 2025/3/20.
//


#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long productAll = 1;
        int countZero = 0;

        for (auto num: nums) {
            if (num == 0) {
                countZero++;
                continue;
            }
            productAll *= num;
        }

        // generate a vector with all 0
        vector<int> result(nums.size());

        if (countZero >= 2) {
            return result;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                result[i] = static_cast<int>(productAll);
                continue;
            }

            if (countZero == 1) {
                result[i] = 0;
                continue;
            }

            result[i] = static_cast<int>(productAll / nums[i]);
        }
        return result;
    }
};