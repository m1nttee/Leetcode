#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<int> capital;

    int findCircleNum(vector<vector<int> > &isConnected) {
        visited.resize(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); i++) {
            dfs(isConnected, i, 0);
        }
        return capital.size();
    }

    void dfs(vector<vector<int> > &isConnected, int visitCityNum, int depth) {
        if (visited[visitCityNum]) {
            return;
        }
        visited[visitCityNum] = true;
        if (depth == 0) {
            capital.push_back(visitCityNum);
        }
        for (int i = 0; i < isConnected[visitCityNum].size(); i++) {
            if (i == visitCityNum) {
                // speed up
                continue;
            }
            if (isConnected[visitCityNum][i] == 1) {
                dfs(isConnected, i, depth + 1);
            }
        }
    }
};
