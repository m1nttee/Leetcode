#include <algorithm>
#include <vector>
#include <ranges>
using namespace std;

class Solution {
public:
    int findIndex(vector<int> &potions, long long successPotion) {
        int low = 0;
        int high = potions.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (potions[mid] < successPotion) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    std::vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        ranges::sort(potions, [&](int a, int b) { return a < b; });
        vector<int> result(spells.size(), 0);
        for (int i = 0; i < spells.size(); ++i) {
            result[i] = potions.size() - findIndex(potions, (success - 1) / spells[i] + 1);
        }
        return result;
    }
};