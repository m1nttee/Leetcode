#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int> > &points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        }); // sort with x value

        int count = 1;
        int k = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            // find next arrow
            if (k > points[i][1]) {
                k = points[i][1];
                continue;
            } // if k is too big, move it backward to points[i][1]
            if (k < points[i][0]) {
                count++;
                k = points[i][1];
                continue;
            } // if k is out of scope of next ballon, start find next arrow.
            if (k < points[i][1]) { continue; } // k is in the scope of next ballon, and it's ok to shot the ballon
        }
        return count;
    }
};
