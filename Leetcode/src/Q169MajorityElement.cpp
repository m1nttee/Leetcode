#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> countMap;
        for (int num: nums) {
            if (!countMap.contains(num)) {
                countMap[num] = 1;
                continue;
            }
            countMap[num] += 1;
        }
        int maxNum = 0;
        int maxCount = INT_MIN;
        for (auto [k, v]: countMap) {
            if (v > maxCount) {
                maxCount = v;
                maxNum = k;
            }
        }

        return maxNum;
    }
};