class LRUCache {
    int cap;
    //            key
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    //   key, val: key is only used to evict
    list<pair<int, int>> vals; // front -> most used

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto itr = cache.find(key);
        if (itr == cache.end()) {
            return -1;
        }
        vals.splice(vals.begin(), vals, itr->second);
        return itr->second->second;
    }

    void put(int key, int value) {
        if (auto itr = cache.find(key); itr != cache.end()) {
            vals.splice(vals.begin(), vals, itr->second);
            itr->second->second = value;
            return;
        } else if (cache.size() == cap) {
            // evict
            cache.erase(vals.back().first);
            vals.pop_back();
        }

        vals.emplace_front(key, value);
        cache[key] = vals.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */