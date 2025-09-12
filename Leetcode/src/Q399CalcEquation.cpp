#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    map<string, vector<pair<string, double> > > equationsMap;
    set<string> visited;

    vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values,
                                vector<vector<string> > &queries) {
        for (int i = 0; i < equations.size(); ++i) {
            equationsMap[equations[i][0]].emplace_back(equations[i][1], values[i]);
            equationsMap[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
        }

        vector<double> result;
        result.reserve(queries.size());
        for (auto &query: queries) {
            double ans;
            if (equationsMap.contains(query[0]) && equationsMap.contains(query[1])) {
                visited = set<string>();
                ans = dfs(query[0], query[1]);
                if (ans == 0) ans = -1;
            } else {
                ans = -1.0;
            }
            result.push_back(ans);
        }
        return result;
    }

    double dfs(const string &from, const string &to) {
        if (visited.contains(from)) return 0;
        visited.insert(from);
        if (from == to) return 1.0;

        for (auto &i: equationsMap[from]) {
            double result = dfs(i.first, to);
            if (result != 0) return result * i.second;
        }

        return 0;
    }
};
