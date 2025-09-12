#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int breakPoint = nums[0];
        if (breakPoint == target) {
            return 0;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            int midVal = nums[mid];
            if (midVal < breakPoint) {
                if (midVal < target && target < breakPoint) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (midVal > target && target > breakPoint) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};


int main(int argc, char *argv[]) {
    // 4,5,6,7,0,1,2
    auto s = Solution();
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    auto ans = s.search(nums, 0);
    printf("%d\n", ans);
}