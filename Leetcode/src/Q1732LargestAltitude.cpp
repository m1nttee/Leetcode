//
// Created by AIINIRII on 2025/3/21.
//


#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int> &gain) {
        int sum = 0, maxSum = 0;
        for (auto num: gain) {
            sum += num;
            if (sum > maxSum) {
                maxSum = sum;
            }
        }

        return maxSum;
    }
};
