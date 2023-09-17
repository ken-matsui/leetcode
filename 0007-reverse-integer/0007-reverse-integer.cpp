class Solution {
public:
    int reverse(int x) {
        try {
            bool neg = x < 0;

            string rev;
            rev += to_string(x);
            ::reverse(rev.begin(), rev.end());

            string res;
            if (neg) {
                res = '-';
            }
            res += rev;
            return stoi(res);
        } catch (...) {
            return 0;
        }
    }
};
