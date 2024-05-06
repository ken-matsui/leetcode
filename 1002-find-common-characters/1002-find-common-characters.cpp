class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char, int>> vm(words.size());
        for (int i = 0; i < words.size(); ++i) {
            unordered_map<char, int> m;
            for (char c : words[i]) {
                m[c]++;
            }
            vm[i] = m;
        }

        vector<string> res;
        for (char c = 'a'; c <= 'z'; ++c) {
            int minCount = INT_MAX;
            for (const auto& m : vm) {
                if (m.contains(c)) {
                    minCount = min(minCount, m.at(c));
                } else {
                    minCount = 0;
                    break;
                }
            }
            for (int i = 0; i < minCount; ++i) {
                res.push_back(string{c});
            }
        }
        return res;
    }
};
