class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 /* pow of 2*/ &&
               (n & 0xAAAAAAAA) == 0;
    }
};
