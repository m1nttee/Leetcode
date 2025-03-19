//
// Created by AIINIRII on 2025/3/19.
//


#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int plantSlotNum = 0;

        // 0 case
        if (flowerbed.empty()) {
            return n <= 0;
        }

        // 1 case
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0) {
                return n <= 1;
            }
            return n <= 0;
        }

        for (int i = 0; i < flowerbed.size(); i++) {
            // head case
            if (i == 0) {
                if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    plantSlotNum++;
                }
                continue;
            }

            // tail case
            if (i == flowerbed.size() - 1) {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    plantSlotNum++;
                }
                continue;
            }

            // other case
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                plantSlotNum++;
            }
        }
        return plantSlotNum >= n;
    }
};


// int main(int argc, char *argv[]) {
//     Solution s;
//     vector flowerbed = {0};
//     cout << s.canPlaceFlowers(flowerbed, 1) << endl;
// }
