class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.begin(), pref.end());
        for (int i = 1; i < pref.size(); ++i) {
            res[i] ^= pref[i - 1];
        }
        return res;
    }
};
