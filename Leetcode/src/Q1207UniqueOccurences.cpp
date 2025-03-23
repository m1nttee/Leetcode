//
// Created by AIINIRII on 2025/3/22.
//


#include <map>
#include<string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> map1;
        for (auto num: arr) {
            if (map1.find(num) == map1.end()) {
                map1[num] = 1;
            }
            else {
                map1[num]++;
            }
        }

        unordered_map<int, int> map2;
        for (auto pair: map1) {
            if (map2.find(pair.second) == map2.end()) {
                map2[pair.second] = 1;
            } else {
                return false;
            }
        }
        return true;
    }
};