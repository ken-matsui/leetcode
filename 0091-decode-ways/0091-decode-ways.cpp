class Solution {
    unordered_map<int, int> dp;

    int traverse(int idx, const string& s) {
        if (dp.find(idx) != dp.end()) {
            return dp[idx];
        }
        if (idx == s.size()) {
            return 1;
        }
        if (s[idx] == '0') {
            return 0;
        }
        if (idx == s.size() - 1) {
            return 1;
        }

        int res = traverse(idx + 1, s);
        if (stoi(s.substr(idx, 2)) <= 26) {
            res += traverse(idx + 2, s);
        }
        dp[idx] = res;
        return res;
    }

public:
    int numDecodings(string s) {
        return traverse(0, s);
    }
};
