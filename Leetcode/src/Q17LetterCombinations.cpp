#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map;
        map.insert({'2', "abc"});
        map.insert({'3', "def"});
        map.insert({'4', "ghi"});
        map.insert({'5', "jkl"});
        map.insert({'6', "mno"});
        map.insert({'7', "pqrs"});
        map.insert({'8', "tuv"});
        map.insert({'9', "wxyz"});
        return dfs(digits, map);
    }

    vector<string> dfs(const string &digits, unordered_map<char, string> map) {
        if (digits.empty()) {
            return {};
        }
        vector<string> ans;
        string s = map[digits[0]];
        auto dfsRes = dfs(digits.substr(1), map);
        if (dfsRes.empty()) {
            for (const auto &c: s) {
                ans.emplace_back(1, c);
            }
        }
        for (const char c: s) {
            for (const auto &ds: dfsRes) {
                ans.push_back(c + ds);
            }
        }
        return ans;
    }
};