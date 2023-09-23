class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double z = 1.;
        long long nn = n;

        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }

        while (nn > 0) {
            if (nn % 2 == 1) {
                z *= x;
            }
            x *= x;
            nn /= 2;
        }
        return z;
    }
};
