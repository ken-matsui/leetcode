class Solution {
public:
    int similarPairs(vector<string>& words) {
        int count = 0;
        vector<unordered_set<char>> v;
        for (const string& w : words) {
            v.push_back(unordered_set<char>(w.begin(), w.end()));
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (v[i] == v[j]) {
                    ++count;
                }
            }
        }
        return count;
    }
};
