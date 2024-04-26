class HitCounter {
    map<int, int> counter;

public:
    HitCounter() {
    }

    void hit(int timestamp) {
        counter[timestamp]++;
    }

    int getHits(int timestamp) {
        int lowbound = timestamp - 299;
        if (lowbound <= 1) {
            lowbound = 1;
        }

        int hits = 0;
        for (auto itr = counter.lower_bound(lowbound);
             itr != counter.upper_bound(timestamp); ++itr) {
            hits += itr->second;
        }
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
