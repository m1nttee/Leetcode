//
// Created by AIINIRII on 2025/3/20.
//


#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // calculate max area by:
        // 1. from height 1 to max, until i >= j
        // 2. i and j's distance must be shrunk
        int h = 1;
        int maxArea = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            if (height[i] < h) {
                i ++;
                continue;
            }
            if (height[j] < h) {
                j --;
                continue;
            }
            // find height[i] >= h and height[j] >= h, update h
            h = min(height[i], height[j]);
            if (const int area = h * (j - i); area > maxArea) {
                maxArea = area;
            }

            // find next h
            h += 1;
        }
        return maxArea;
    }
};