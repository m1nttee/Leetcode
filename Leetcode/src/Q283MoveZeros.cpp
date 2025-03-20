//
// Created by AIINIRII on 2025/3/20.
//


#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int insertIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[insertIndex] = nums[i];
                if (insertIndex != i) {
                    nums[i] = 0;
                }
                insertIndex++;
            }
        }
    }
};
