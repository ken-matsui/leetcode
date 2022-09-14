class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(), 'a');
        int i = 0;
        for (const int j : indices) {
            ans[j] = s[i++];
        }
        return ans;
    }
};
