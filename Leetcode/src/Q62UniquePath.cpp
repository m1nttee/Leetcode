#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp1 = std::vector<int>(m, 1);
        std::vector<int> dp2 = std::vector<int>(m, 1);

        std::vector<int> *dpNow = &dp1;
        std::vector<int> *dpNew = &dp2;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                (*dpNew)[j] = (*dpNow)[j] + (*dpNew)[j - 1];
            }
            std::vector<int> *tmp = dpNow;
            dpNow = dpNew;
            dpNew = tmp;
        }

        return (*dpNow)[m - 1];
    }
};