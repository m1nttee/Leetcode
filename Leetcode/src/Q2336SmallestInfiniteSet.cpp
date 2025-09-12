#include <queue>
#include <vector>
using namespace std;

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<> > pq;
    int autoInc = 1;

    SmallestInfiniteSet() {
    }

    int popSmallest() {
        // if it's empty, we use autoInc
        if (pq.empty()) {
            return autoInc++;
        }
        // otherwise, we check the top value of pq
        int ans = pq.top();
        // if top value of pq is smaller than ans, which means we should pop the pq value
        while (pq.top() == ans && !pq.empty()) {
            pq.pop();
        }
        return ans;
    }

    void addBack(int num) {
        if (num < autoInc) {
            pq.push(num);
        }
    }
};
