class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        
        unsigned long long powed = n;
        for (int i = 0; i < 10000; ++i) {
            string s = to_string(powed);
            powed = 0;
            for (char c : s) {
                powed += pow(c - '0', 2);
            }
            if (powed == 1) {
                return true;
            }
        }
        return false;
    }
};