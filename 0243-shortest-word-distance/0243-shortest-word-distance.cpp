class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> words;
        for (int i = 0; i < wordsDict.size(); ++i) {
            words[wordsDict[i]].push_back(i);
        }
        
        int minDist = INT_MAX;
        for (int i : words[word1]) {
            for (int j : words[word2]) {
                minDist = min(minDist, abs(i - j));
            }
        }
        return minDist;
    }
};
