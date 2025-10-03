#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    vector<int> values;
    unordered_map<int, int> valuesToVIndex;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (!valuesToVIndex.contains(val)) {
            values.push_back(val);
            valuesToVIndex[val] = values.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (valuesToVIndex.contains(val)) {
            int vIndex = valuesToVIndex[val];
            valuesToVIndex.erase(val);
            if (values.size() - 1 != vIndex) {
                int lastVal = values[values.size() - 1];
                valuesToVIndex[lastVal] = vIndex;
                swap(values[vIndex], values[values.size() - 1]);
            }
            values.pop_back();
            return true;
        }
        return false;
    }

    int getRandom() {
        int randIndex = random() % values.size();
        return values[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char *argv[]) {
    auto rs = RandomizedSet();
    rs.remove(0);
    rs.remove(0);
    rs.insert(0);
    rs.getRandom();
    rs.remove(0);
    rs.insert(0);
    return 0;
}