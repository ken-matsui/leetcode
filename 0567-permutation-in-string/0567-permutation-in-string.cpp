class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<char, int> s1Freq;
        for (const char c1 : s1) {
            s1Freq[c1]++;
        }

        for (int i = 0; i <= s2.size() - s1.size(); ++i) {
            unordered_map<char, int> s2Freq;
            for (int j = 0; j < s1.size(); ++j) {
                s2Freq[s2[i + j]]++;
            }

            bool match = true;
            for (const auto& itr : s1Freq) {
                if (itr.second - s2Freq[itr.first] != 0) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;
            }
        }
        return false;
    }
};
