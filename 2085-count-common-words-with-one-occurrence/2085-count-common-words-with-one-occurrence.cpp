class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1;
        for (const string& w : words1) {
            m1[w]++;
        }
        unordered_map<string, int> m2;
        for (const string& w : words2) {
            m2[w]++;
        }

        int count = 0;
        for (const auto& [w, f] : m1) {
            if (f == 1) {
                if (m2[w] == 1) {
                    ++count;
                }
            }
        }
        return count;
    }
};
