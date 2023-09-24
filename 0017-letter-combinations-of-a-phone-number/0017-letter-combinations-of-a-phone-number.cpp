class Solution {
    vector<string> letters = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    void backtrack(const string& digits, const int idx, string& cur) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }

        for (const char c : letters[digits[idx] - '0']) {
            cur.push_back(c);
            backtrack(digits, idx + 1, cur);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        string cur;
        backtrack(digits, 0, cur);
        return res;
    }
};
