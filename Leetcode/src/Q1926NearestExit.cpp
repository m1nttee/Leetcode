#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char> > &maze, vector<int> &entrance) {
        size_t rows = maze.size();
        size_t cols = maze[0].size();
        for (int i = 0; i < rows; ++i) {
            if (maze[i][0] == '.') {
                maze[i][0] = '#';
            }
            if (maze[i][cols - 1] == '.') {
                maze[i][cols - 1] = '#';
            }
        }
        for (int j = 0; j < cols; ++j) {
            if (maze[0][j] == '.') {
                maze[0][j] = '#';
            }
            if (maze[rows - 1][j] == '.') {
                maze[rows - 1][j] = '#';
            }
        }

        auto bfsQ = queue<pair<int, int> >();
        bfsQ.emplace(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        while (!bfsQ.empty()) {
            steps += 1;
            int size = bfsQ.size();
            for (int i = 0; i < size; ++i) {
                int x = bfsQ.front().first;
                int y = bfsQ.front().second;
                bfsQ.pop();

                if ((x + 1 < rows && maze[x + 1][y] == '#') || // Check down
                    (x - 1 >= 0 && maze[x - 1][y] == '#') || // Check up
                    (y + 1 < cols && maze[x][y + 1] == '#') || // Check right
                    (y - 1 >= 0 && maze[x][y - 1] == '#') // Check left
                ) {
                    return steps;
                }

                if (y + 1 < cols && maze[x][y + 1] == '.') {
                    bfsQ.emplace(x, y + 1);
                    maze[x][y + 1] = '+';
                }
                if (y - 1 >= 0 && maze[x][y - 1] == '.') {
                    bfsQ.emplace(x, y - 1);
                    maze[x][y - 1] = '+';
                }
                if (x + 1 < rows && maze[x + 1][y] == '.') {
                    bfsQ.emplace(x + 1, y);
                    maze[x + 1][y] = '+';
                }
                if (x - 1 >= 0 && maze[x - 1][y] == '.') {
                    bfsQ.emplace(x - 1, y);
                    maze[x - 1][y] = '+';
                }
            }
        }
        return -1;
    }
};
