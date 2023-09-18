class Solution {
public:
    string reverseWords(string s) {
        string res;
        string cur;
        for (char c : s) {
            if (c == ' ') {
                reverse(cur.begin(), cur.end());
                res += cur + ' ';
                cur = "";
            } else {
                cur += c;
            }
        }
        if (!cur.empty()) {
            reverse(cur.begin(), cur.end());
            res += cur;
        }
        return res;
    }
};
