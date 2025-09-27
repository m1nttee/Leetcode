#include <queue>
#include <set>
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    struct pair_less {
        bool operator ()(const pair<int, int> &a, const pair<int, int> &b) const {
            return a.second < b.second;
        }
    };

public:
    int networkDelayTime(vector<vector<int> > &times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, pair_less> unvisited;
        vector<int> visited = vector(n, INT32_MAX);
        unordered_map<int, vector<pair<int, int> > > edges;
        for (auto &time: times) {
            int from = time[0];
            int to = time[1];
            int weight = time[2];
            if (!edges.contains(from)) {
                edges[from] = vector<pair<int, int> >();
            }
            edges[from].emplace_back(to, weight);
        }

        // init unvisited
        auto edges_v = edges[k];
        for (auto edge: edges_v) {
        }
    }
};