#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        vector jumpSteps(nums.size(), INT_MAX);
        jumpSteps[0] = 0;
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = maxReach - i + 1; j <= nums[i] && i + j < nums.size(); ++j) {
                jumpSteps[i + j] = jumpSteps[i] + 1;
            }
            maxReach = max(maxReach, nums[i] + i);
        }
        return jumpSteps[nums.size() - 1];
    }
};