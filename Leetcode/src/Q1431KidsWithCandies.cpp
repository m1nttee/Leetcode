//
// Created by AIINIRII on 2025/3/19.
//

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        std::vector<bool> result;

        int maxCandies = 0;
        ranges::for_each(candies, [&](int c) {
            maxCandies = max(maxCandies, c);
        });
        ranges::for_each(candies, [&](int c) {
            result.push_back(c + extraCandies >= maxCandies);
        });

        return result;
    }
};
