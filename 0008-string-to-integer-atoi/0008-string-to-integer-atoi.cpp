class Solution {
public:
    int myAtoi(string s) {
        const int n = s.size();
        int i = 0;
        while (i < n && isspace(s[i])) {
            ++i;
        }

        bool isNegative = false;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            isNegative = s[i] == '-';
            ++i;
        }

        long long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            if (!isNegative && res >= INT_MAX) {
                return INT_MAX;
            }
            if (isNegative && -res <= INT_MIN) {
                return INT_MIN;
            }

            ++i;
        }
        return isNegative ? -res : res;
    }
};
