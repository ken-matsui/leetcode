class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t a = 1;
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if ((a & n) >> i) {
                ++count;
            }
            a <<= 1;
        }
        return count;
    }
};
