#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(std::vector<int> &cost) {
        if (cost.size() < 2) return 0;
        int minCost[] = {cost[0], cost[1]};
        for (int i = 2; i < cost.size(); i++) {
            int minCosti = min(minCost[0] + cost[i], minCost[1] + cost[i]);
            minCost[0] = minCost[1];
            minCost[1] = minCosti;
        }
        return min(minCost[0], minCost[1]);
    }
};