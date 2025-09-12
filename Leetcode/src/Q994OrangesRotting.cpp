#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int> > &grid) {
        queue<pair<int, int> > q;
        pair<int, int> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }

        int steps = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto &direction: directions) {
                    int nx = x + direction.first;
                    int ny = y + direction.second;

                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] != 1) {
                        continue;
                    }

                    q.emplace(nx, ny);
                    grid[nx][ny] = 2;
                }
            }

            steps++;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return max(steps, 0);
    }
};
