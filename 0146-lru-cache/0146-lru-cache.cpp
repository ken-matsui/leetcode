class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, decltype(cache)::iterator> dic;

public:
    LRUCache(int capacity) : capacity(capacity) {
    }

    int get(int key) {
        const auto itr = dic.find(key);
        if (itr == dic.end()) {
            return -1;
        }

        const int val = itr->second->second;
        cache.erase(itr->second);
        cache.push_front({key, val});

        dic.erase(itr);
        dic[key] = cache.begin();
        return val;
    }

    void put(int key, int value) {
        const auto itr = dic.find(key);
        if (itr != dic.end()) {
            cache.erase(itr->second);
            dic.erase(itr);
        }

        cache.push_front({key, value});
        dic[key] = cache.begin();

        if (dic.size() > capacity) {
            const auto last = dic.find(cache.rbegin()->first);
            dic.erase(last);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
