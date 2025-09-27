#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1;
        int right = 0;
        for (int pile: piles) {
            right = max(right, pile);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            int midH = computeH(piles, mid);
            if (h < midH) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    static int computeH(vector<int> &piles, int k) {
        int h = 0;
        for (int pile: piles) {
            h += (pile - 1) / k + 1;
        }
        return h;
    }
};