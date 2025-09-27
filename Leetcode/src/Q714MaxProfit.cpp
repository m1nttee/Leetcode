#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        size_t sz = prices.size();
        vector<int> dp(sz, 0);
        vector<int> b(sz, 0);
        dp[0] = 0;
        b[0] = -prices[0];
        for (size_t i = 1; i < sz; i++) {
            dp[i] = max(b[i - 1] + prices[i] - fee, dp[i - 1]);
            b[i] = max(b[i - 1], dp[i - 1] - prices[i]);
        }
        return dp[sz - 1];
    }
};