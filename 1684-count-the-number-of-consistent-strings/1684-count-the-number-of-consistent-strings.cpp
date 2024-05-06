class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        const unordered_set<char> allowed_set(allowed.begin(), allowed.end());
        int count = 0;
        for (const string& w : words) {
            if (all_of(w.begin(), w.end(), [&](char c){ return allowed_set.contains(c); })) {
                ++count;
            }
        }
        return count;
    }
};