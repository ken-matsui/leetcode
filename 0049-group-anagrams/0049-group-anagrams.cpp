class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) {
            return {strs};
        }
        
        sort(strs.begin(), strs.end());
        const vector<string> cpy(strs.begin(), strs.end());
        for (auto& s : strs) {
            sort(s.begin(), s.end());
        }

        vector<vector<string>> result;
        vector<int> visited;
        for (int i = 0; i < strs.size(); ++i) {
            if (find(visited.begin(), visited.end(), i) != visited.end()) {
                continue;
            }

            vector<string> res = {cpy[i]};
            visited.emplace_back(i);
            for (int j = i + 1; j < strs.size(); ++j) {
                if (strs[i] == strs[j]) {
                    res.emplace_back(cpy[j]);
                    visited.emplace_back(j);
                }
            }
            result.emplace_back(res);
        }
        return result;
    }
};
