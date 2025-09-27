#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
public:
    vector<int> stocks;
    stack<int> stk;

    StockSpanner() {
        stocks.reserve(100000);
    }

    int next(int price) {
        stocks.emplace_back(price);
        while (!stk.empty() && stocks[stk.top()] <= price) {
            stk.pop();
        }
        int i = stocks.size() - 1;
        int j = -1;
        if (!stk.empty()) {
            j = stk.top();
        }
        stk.push(stocks.size() - 1);
        return i - j;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
