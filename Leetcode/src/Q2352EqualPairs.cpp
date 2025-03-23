//
// Created by AIINIRII on 2025/3/22.
//


#include <iostream>
#include <ostream>
#include<string>
#include <unordered_map>
#include <vector>
using namespace std;

struct VectorHash {
    std::size_t operator()(const vector<int> &v) const {
        std::size_t seed = 0;
        for (const int &x: v) {
            seed = seed * 31 + x;
            seed %= 1000000007;
        }
        return seed;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int> > &grid) {
        unordered_map<vector<int>, int, VectorHash> rowMap;
        unordered_map<vector<int>, int, VectorHash> colMap;
        for (int i = 0; i < grid.size(); i++) {
            rowMap[grid[i]] += 1;
        }

        for (int i = 0; i < grid.size(); i++) {
            vector<int> col(grid[i].size(), 0);
            for (int j = 0; j < grid[i].size(); j++) {
                col[j] = grid[j][i];
            }
            colMap[col] += 1;
        }

        int res = 0;
        for (auto pair: rowMap) {
            if (colMap.contains(pair.first)) {
                res += colMap[pair.first] * pair.second;
            }
        }
        return res;
    }
};

// int main(int argc, char *argv[]) {
//     Solution solution;
//     vector<vector<int> > vector = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
//     cout << solution.equalPairs(vector) << endl;
// }
