#include <stdint.h>
#include <vector>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int> &nums, int value) {
        vector<int> counter(value, 0);
        for (auto num: nums) {
            int mod = num % value;
            if (mod < 0) {
                mod += value;
            }
            counter[mod]++;
        }

        int min_index = 0;
        for (int i = 0; i < value; i++) {
            if (counter[i] < counter[min_index]) {
                min_index = i;
            }
        }
        return min_index + counter[min_index] * value;
    }
};
