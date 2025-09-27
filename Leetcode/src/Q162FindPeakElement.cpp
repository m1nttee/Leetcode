#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midS = 0;
            if (nums[mid] - nums[mid + 1] > 0) {
                midS = -1;
            } else {
                midS = 1;
            }

            if (midS == 1) {
                left = mid + 1;
            }
            if (midS == -1) {
                right = mid;
            }
        }

        return left;
    }
};