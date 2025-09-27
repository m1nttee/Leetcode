#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        return dfs(k, n, 9);
    }

    vector<vector<int> > dfs(int k, int n, int max) {
        vector<vector<int> > res;
        if (k == 1) {
            if (n > max || n < 1) return {};
            return {{n}};
        }

        for (int i = 1; i <= max; i++) {
            auto dfsRes = dfs(k - 1, n - i, i - 1);
            for (auto v: dfsRes) {
                v.push_back(i);
                res.push_back(v);
            }
        }
        return res;
    }
};