class Solution {
    vector<vector<string>> res;
    
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }

    void backtrack(const string& s, vector<string>& cur, const int start) {
        if (start == s.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int end = start; end < s.size(); ++end) {
            if (!isPalindrome(s, start, end)) {
                continue;
            }
            cur.push_back(s.substr(start, end - start + 1));
            backtrack(s, cur, end + 1);
            cur.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backtrack(s, cur, 0);
        return res;
    }
};
