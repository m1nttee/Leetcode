#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        set<int> appearedNums;
        for (auto &num: nums) {
            if (appearedNums.find(num) != appearedNums.end()) {
                appearedNums.erase(num);
            } else {
                appearedNums.insert(num);
            }
        }
        return *appearedNums.begin();
    }
};