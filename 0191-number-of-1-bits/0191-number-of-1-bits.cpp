class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (; n; ++count) {
            n &= n - 1;
        }
        return count;
    }
};
