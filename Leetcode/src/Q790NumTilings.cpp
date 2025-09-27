#include <vector>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        std::vector<long> ans(n + 1, 0);
        ans[1] = 1;
        ans[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                long c = (i - j) <= 2 ? 1 : 2;
                ans[i] += (ans[j] * c) % static_cast<long>(10e9 + 7);
            }
            ans[i] += 2;
        }

        return ans[n] % static_cast<long>(10e9 + 7);
    }
};