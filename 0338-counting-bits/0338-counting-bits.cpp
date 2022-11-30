class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (; n; ++count) {
            n &= n - 1;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> res;
        do {
            res.emplace_back(hammingWeight(n));
            --n;
        } while (n >= 0);
        reverse(res.begin(), res.end());
        return res;
    }
};
