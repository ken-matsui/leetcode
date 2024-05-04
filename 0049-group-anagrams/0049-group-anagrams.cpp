class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) {
            return {};
        } else if (strs.size() == 1) {
            return {strs};
        }
        
        vector<string> cpy(strs.begin(), strs.end());
        for (string& s : cpy) {
            sort(s.begin(), s.end());
        }
        
        unordered_map<string, unordered_set<int>> anag;
        for (int i = 0; i < strs.size(); ++i) {
            anag[cpy[i]].insert(i);
        }

        vector<vector<string>> res;
        for (auto [s, is] : anag) {
            vector<string> inner;
            for (int i : is) {
                inner.push_back(strs[i]);
            }
            res.push_back(inner);
        }
        return res;
    }
};
