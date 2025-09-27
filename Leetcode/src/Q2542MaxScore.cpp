#include <algorithm>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    struct bigger_pair {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
            return a.second > b.second || (a.second == b.second && a.first > b.first);
        }
    };

public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, int> > nums;
        nums.reserve(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            nums.emplace_back(nums1[i], nums2[i]);
        }
        ranges::sort(nums.begin(), nums.end(), bigger_pair());
        long long sum = 0;
        priority_queue<int, vector<int>, greater<> > pq;
        for (int i = 0; i < k; i++) {
            cout << nums[i].second << " ";
            sum += nums[i].first;
            pq.push(nums[i].first);
        }
        priority_queue<long long> result;
        result.push(sum * nums[k - 1].second);
        for (int i = k; i < nums.size(); i++) {
            long long remove = pq.top();
            sum -= remove;
            sum += nums[i].first;

            pq.pop();
            pq.push(nums[i].first);
            result.push(sum * nums[i].second);
        }
        return result.top();
    }
};