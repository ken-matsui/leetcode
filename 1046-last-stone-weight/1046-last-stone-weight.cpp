class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> buckets(1001, 0);
        for (const int stone : stones) {
            buckets[stone]++;
        }

        int biggest = 0;
        int idx = 1000;
        while (idx > 0) {
            if (buckets[idx] == 0) {
                --idx;
                continue;
            }

            if (biggest == 0) {
                buckets[idx] %= 2;
                if (buckets[idx] == 1) {
                    biggest = idx;
                }
                --idx;
            } else {
                buckets[idx]--;
                if (biggest - idx <= idx) {
                    buckets[biggest - idx]++;
                    biggest = 0;
                } else {
                    biggest -= idx;
                }
            }
        }
        return biggest;
    }
};
