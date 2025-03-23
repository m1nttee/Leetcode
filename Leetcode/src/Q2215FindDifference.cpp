//
// Created by AIINIRII on 2025/3/22.
//


#include<string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1, map2;
        for (auto num: nums1) {
            if (map1.find(num) == map1.end()) {
                map1[num] = 1;
            }
        }
        for (auto num: nums2) {
            if (map2.find(num) == map2.end()) {
                map2[num] = 1;
            }
        }

        vector<int> res1;
        for (auto pair: map1) {
            if (map2.find(pair.first) == map2.end()) {
                res1.push_back(pair.first);
            }
        }
        vector<int> res2;
        for (auto pair: map2) {
            if (map1.find(pair.first) == map1.end()) {
                res2.push_back(pair.first);
            }
        }

        vector<vector<int>> res;
        res.push_back(res1);
        res.push_back(res2);

        return res;
    }
};