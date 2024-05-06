class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> st1;
        unordered_map<string, int> st2;

        string word;

        istringstream ss1(s1);
        while (ss1 >> word) {
            st1[word]++;
        }

        istringstream ss2(s2);
        while (ss2 >> word) {
            st2[word]++;
        }

        vector<string> res;
        for (const auto& [s, f] : st1) {
            if (f != 1) {
                continue;
            }

            if (!st2.contains(s)) {
                res.push_back(s);
            }
        }
        for (const auto& [s, f] : st2) {
            if (f != 1) {
                continue;
            }

            if (!st1.contains(s)) {
                res.push_back(s);
            }
        }
        return res;
    }
};
