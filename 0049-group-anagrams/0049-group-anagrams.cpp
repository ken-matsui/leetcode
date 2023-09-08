class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> grp;
        
        for (const string& s : strs) {
            string cpy = s;
            sort(cpy.begin(), cpy.end());
            grp[cpy].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (const auto& [k, v] : grp) {
            ans.push_back(v);
        }
        return ans;
    }
};