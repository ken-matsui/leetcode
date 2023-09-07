class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int count = 0;
        for (const char c : s) {
            if (c == ' ') {
                ++count;
                if (count == k) {
                    return res;
                }
            }
            res += c;
        }
        return res;
    }
};
