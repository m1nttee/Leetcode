//
// Created by AIINIRII on 2025/3/23.
//


#include <iostream>
#include <ostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> sStack;
        for (auto asteroid: asteroids) {
            if (sStack.empty()) {
                sStack.push_back(asteroid);
                continue;
            }

            if (asteroid > 0) {
                sStack.push_back(asteroid);
                continue;
            }

            bool asteroidDestroyed = false;
            while (!sStack.empty() && sStack.back() > 0 && !asteroidDestroyed) {
                if (sStack.back() > -asteroid) {
                    asteroidDestroyed = true;
                } else if (sStack.back() == -asteroid) {
                    sStack.pop_back();
                    asteroidDestroyed = true;
                } else {
                    sStack.pop_back();
                }
            }

            if (!asteroidDestroyed) {
                sStack.push_back(asteroid);
            }
        }

        return sStack;
    }
};


// int main(int argc, char *argv[]) {
//     Solution s;
//     vector asteroids = {5, 10, -5};
//     auto result = s.asteroidCollision(asteroids);
//     for (auto i: result) {
//         cout << i << " ";
//     }
//     cout << endl;
// }
