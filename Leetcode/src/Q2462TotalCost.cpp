#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<> > left;
        priority_queue<int, vector<int>, greater<> > right;
        int i = 0;
        int j = costs.size() - 1;
        if (j + 1 < candidates * 2) {
            for (int cost: costs) {
                left.push(cost);
            }
            int ans = left.top();
            left.pop();
            for (int m = 1; m < k; m++) {
                ans += left.top();
                left.pop();
            }
            return ans;
        }

        for (int m = 0; m < candidates; m++) {
            left.push(costs[m]);
            right.push(costs[j - m]);
        }
        i += candidates - 1;
        j -= candidates - 1;

        long long ans = 0;
        while (i + 1 < j) {
            if (k <= 0) break;
            k--;

            int leftV = left.top();
            int rightV = right.top();

            if (leftV <= rightV) {
                // choose leftV
                ans += leftV;
                left.pop();
                cout << leftV << endl;
                i += 1;
                left.push(costs[i]);
            } else {
                // choose rightV
                ans += rightV;
                right.pop();
                cout << rightV << endl;
                j -= 1;
                right.push(costs[j]);
            }
        }

        while (k > 0) {
            k--;
            if (left.empty()) {
                ans += right.top();
                right.pop();
                continue;
            }
            if (right.empty()) {
                ans += left.top();
                left.pop();
                continue;
            }

            int leftV = left.top();
            int rightV = right.top();

            if (leftV <= rightV) {
                // choose leftV
                ans += leftV;
                cout << leftV << endl;
                left.pop();
            } else {
                // choose rightV
                ans += rightV;
                cout << rightV << endl;
                right.pop();
            }
        }
        return ans;
    }
};