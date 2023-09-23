class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> rows(numRows);
        bool backward = true;
        int idx = 0;
        for (const char c : s) {
            rows[idx] += c;
            if (idx == 0 || idx == numRows - 1) {
                backward = !backward;
            }
            if (backward) {
                --idx;
            } else {
                ++idx;
            }
        }
        
        string res;
        for (const string& r : rows) {
            res += r;
        }
        return res;
    }
};