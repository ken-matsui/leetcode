class Solution {
public:
    int balancedStringSplit(string s) {
        const size_t size = s.size();
        
        char cur = s[0];
        int count = 1;
        int output = 0;
        for (int i = 1; i < size; ++i) {
            if (cur != s[i] && count != 0) {
                --count;
                if (count == 0) {
                    ++output;
                    if (i != size) {
                        cur = s[i + 1];
                    }
                }
            } else {
                ++count;
            }
        }
        return output;
    }
};