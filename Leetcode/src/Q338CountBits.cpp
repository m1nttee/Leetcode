#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // 0 ｜ 1 ｜ 1 2 ｜ 1 2 2 3 ｜ 1 2 2 3 2 3 3 4 ｜ 1
        vector<int> res;
        res.reserve(n + 1);
        res.push_back(0);
        int k = 1;
        for (int i = 1; i <= n; i++) {
            res.emplace_back(res[i - k] + 1);
            if (i >= 2 * k - 1) {
                k <<= 1;
            }
        }
        return res;
    }
};