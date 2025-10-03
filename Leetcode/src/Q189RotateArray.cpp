#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        vector<int> nums_cp = vector(nums);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[(i + k) % n] = nums_cp[i];
        }
    }
};