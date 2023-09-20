class TimeMap {
    unordered_map<string, map<int, string>> m;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto itr = m[key].upper_bound(timestamp);
        if (itr != m[key].begin()) {
            --itr;
            return itr->second;
        } else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
