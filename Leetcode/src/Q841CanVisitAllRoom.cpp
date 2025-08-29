#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visited;

    bool canVisitAllRooms(vector<vector<int> > &rooms) {
        visited.resize(rooms.size(), false);
        dfs(rooms, 0);
        for (auto v: visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int> > &rooms, int visitRoomNum) {
        if (visited[visitRoomNum]) {
            return;
        }
        visited[visitRoomNum] = true;

        for (auto key: rooms[visitRoomNum]) {
            dfs(rooms, key);
        }
    }
};
