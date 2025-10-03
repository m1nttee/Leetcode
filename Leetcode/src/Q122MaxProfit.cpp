#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // find increase subarray
        int increased_from = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] > prices[i]) {
                profit += prices[i - 1] - prices[increased_from];
                increased_from = i;
            }
        }
        profit += prices[prices.size() - 1] - prices[increased_from];
        return profit;
    }
};