#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int lastVal = nums[0];
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == lastVal) continue;
            lastVal = nums[i];
            nums[k++] = nums[i];
        }
        return k;
    }
};