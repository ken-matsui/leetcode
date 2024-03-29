class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups(s.size());
        groups[0] = 1;
        int t = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] != s[i]) {
                ++t;
                groups[t] = 1;
            } else {
                groups[t]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= t; ++i) {
            ans += min(groups[i - 1], groups[i]);
        }
        return ans;
    }
};
