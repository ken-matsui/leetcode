class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        for (int i = 0, j = 0; i < s.size() && j < t.size();) {
            if (s[i] == t[j]) {
                if (i == s.size() - 1) {
                    return true;
                }
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return false;
    }
};
