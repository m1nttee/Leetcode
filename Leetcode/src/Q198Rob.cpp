#include <vector>

using namespace std;

class Solution {
public:
    int rob(std::vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int res[] = {nums[0], nums[1]};
        for (int i = 2; i < nums.size(); i++) {
            int resi1 = max(res[0], res[1]);
            int resi2 = max(res[0] + nums[i], res[1]);
            res[0] = resi1;
            res[1] = resi2;
        }
        return max(res[0], res[1]);
    }
};