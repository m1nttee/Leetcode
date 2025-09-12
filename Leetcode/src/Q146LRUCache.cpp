#include <list>
#include <unordered_map>
#include<vector>
using namespace std;

class LRUCache {
    unordered_map<int, int> cache;
    list<int> used_keys;
    int capacity;

public:
    LRUCache(int capacity) {
        cache.clear();
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.contains(key)) {
            for (auto it = used_keys.begin(); it != used_keys.end(); ++it) {
                if (*it == key) {
                    used_keys.erase(it);
                    used_keys.push_front(key);
                    break;
                }
            }
            return cache[key];
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            for (auto it = used_keys.begin(); it != used_keys.end(); ++it) {
                if (*it == key) {
                    used_keys.erase(it);
                    used_keys.push_front(key);
                    break;
                }
            }
            cache[key] = value;
            return;
        }

        if (cache.size() + 1 > capacity) {
            // drop the least recently used item
            int lru_key = used_keys.back();
            used_keys.pop_back();
            cache.erase(lru_key);
        }

        cache[key] = value;
        used_keys.push_front(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
