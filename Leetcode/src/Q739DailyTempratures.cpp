#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> stack;
        vector result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int j = stack.top();
                stack.pop();
                result[j] = i - j;
            }
            stack.push(i);
        }
        return result;
    }
};
