class Solution {
public:
    string sortSentence(string s) {
        vector<string> sv{""};
        vector<int> iv{};

        int i = 0;
        for (const char c : s) {
            if (isdigit(c)) { // containing no more than 9 words
                iv.push_back((c - '0') - 1);
                ++i;
                sv.push_back("");
            } else if (isalpha(c)) {
                sv[i].push_back(c);
            }
        }

        i = 0;
        const size_t size = iv.size();
        vector<string> sv2(size);
        for (const int i2 : iv) {
            sv2[i2] = sv[i++];
        }

        string ans{};
        for (const string& s2 : sv2) {
            ans += s2 + " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};
