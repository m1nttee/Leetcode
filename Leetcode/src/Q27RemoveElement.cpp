#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) continue;
            nums[k++] = nums[i];
        }
        return k;
    }
};