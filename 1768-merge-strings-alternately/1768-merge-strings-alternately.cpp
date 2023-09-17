class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        
        const int n = min(word1.size(), word2.size());
        for (int i = 0; i < n; ++i) {
            res += word1[i];
            res += word2[i];
        }
        
        const string word3 = word1.size() > word2.size() ? word1 : word2;
        for (int i = n; i < word3.size(); ++i) {
            res += word3[i];
        }

        return res;
    }
};