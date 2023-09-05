class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int left = static_cast<int>(exp(0.5 * log(x)));
        int right = left + 1;
        return static_cast<long>(right) * right > x ? left : right;
    }
};
