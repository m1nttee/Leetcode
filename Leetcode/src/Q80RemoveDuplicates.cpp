#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int lastVal = nums[0];
        int lastValTimes = 1;
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == lastVal) {
                if (lastValTimes <= 1) {
                    lastValTimes += 1;
                    nums[k++] = nums[i];
                }
                continue;
            }
            lastValTimes = 1;
            lastVal = nums[i];
            nums[k++] = nums[i];
        }
        return k;
    }
};