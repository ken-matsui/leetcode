class Solution {
public:
    bool all_same(const int index, const vector<string>& strs) {
        for (int j = 0; j < strs.size() - 1; ++j) {
            if (strs[j][index] != strs[j + 1][index]) {
                return false;
            }
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        const string min_str =
            *min_element(
                strs.begin(), strs.end(), 
                [] (const string& s1, const string& s2) { 
                    return s1.length() < s2.length();
                }
            );
        const size_t min_size = min_str.size();

        for (int i = 0; i < min_size; ++i) {
            if (!all_same(i, strs)) {
                return min_str.substr(0, i);
            }
        }
        return min_str;
    }
};