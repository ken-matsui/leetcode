class Solution {
    void dfs(string current, int openRem, int closeRem,
             vector<string>& result) {
        if (openRem == 0 && closeRem == 0) {
            result.push_back(current);
            return;
        }

        if (openRem > 0) {
            dfs(current + "(", openRem - 1, closeRem, result);
        }
        if (closeRem > openRem) {
            dfs(current + ")", openRem, closeRem - 1, result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs("", n, n, result);
        return result;
    }
};
