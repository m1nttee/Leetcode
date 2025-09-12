#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        // min price until now
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;
            // every time we add a new price, and try to sell at that point
            if (profit > maxProfit) {
                maxProfit = profit;
            }
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};
