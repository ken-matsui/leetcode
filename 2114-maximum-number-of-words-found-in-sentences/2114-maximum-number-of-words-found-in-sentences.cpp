class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = -1;
        for (const string& s : sentences) {
            const int curWords = count(s.begin(), s.end(), ' ') + 1;
            maxWords = max(maxWords, curWords);
        }
        return maxWords;
    }
};
