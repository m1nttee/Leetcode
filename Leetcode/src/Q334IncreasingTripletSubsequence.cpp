//
// Created by AIINIRII on 2025/3/20.
//


#include <iostream>
#include<string>
#include<vector>
using namespace std;

// 1. record the min value
// 2. find a num with index j, which is smaller than a num before it
// 3. when a new num come in, need to judge:
//    a. if it's bigger than num[j], that's it!
//    b. if it's smaller than num[j], then:
//       i. if it's min, it's useless.
//      ii. if it's bigger than min, then that's new j.
class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int min = INT_MAX;
        int j = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < min) {
                min = nums[i];
            }

            // find first up point
            if (min < nums[i] && (j < 0 || nums[i] < nums[j])) {
                j = i;
            }

            if (j > 0 && nums[j] < nums[i]) {
                return true;
            }
        }
        return false;
    }
};

// int main(int argc, char *argv[]) {
//     Solution s;
//     vector<int> nums = {1,2,3,4,5,6};
//     cout << s.increasingTriplet(nums) << endl;
// }
