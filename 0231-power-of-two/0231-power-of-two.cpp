class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1 || n == 2) {
            return true;
        }
        
        unsigned long long val = 4;
        for (int i = 3; i <= 31; ++i) {
            if (val == n) {
                return true;
            }
            val *= 2;
        }
        return false;
    }
};
