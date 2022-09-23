class Solution {
public:
    inline int arrVal(int i) const {
        return (2 * i) + 1;
    }

    int minOperations(int n) {
        int sum = 0;
        if (n % 2 == 1) {
            const int mid = n / 2;
            const int midVal = arrVal(mid);
            for (int i = 0; i < mid; ++i) {
                sum += midVal - arrVal(i);
            }
        } else {
            ++sum;

            const int mid = n / 2 - 1;
            const int midVal = arrVal(mid) + 1;
            for (int i = 0; i < mid; ++i) {
                sum += midVal - arrVal(i);
            }
        }
        return sum;
    }
};
