#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    // from[<to, isPos?>]
    vector<vector<pair<int, bool> > > roadMap;
    vector<bool> visited;

    int minReorder(int n, vector<vector<int> > &connections) {
        visited = vector(n, false);
        roadMap = vector(n, vector<pair<int, bool> >());
        for (int i = 0; i < n - 1; i++) {
            if (roadMap.size() == connections[i][0]) {
                roadMap[connections[i][0]] = vector<pair<int, bool> >();
            }
            if (roadMap.size() == connections[i][1]) {
                roadMap[connections[i][1]] = vector<pair<int, bool> >();
            }
            roadMap[connections[i][0]].emplace_back(connections[i][1], true);
            roadMap[connections[i][1]].emplace_back(connections[i][0], false);
        }
        return dfs(0);
    }

    int dfs(int dest) {
        if (visited[dest]) {
            return 0;
        }
        visited[dest] = true;

        int reversed = 0;
        for (auto &i: roadMap[dest]) {
            if (!visited[i.first]) {
                if (i.second) reversed += 1;
                reversed += dfs(i.first);
            }
        }

        return reversed;
    }
};
