class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        
        vector<bool> canBreak(s.size() + 1, false);
        canBreak[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (canBreak[j] && words.find(s.substr(j, i - j)) != words.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }

        return canBreak[s.size()];
    }
};