class Solution {
    vector<string> banned;
    
    bool isNotBanned(const string& str) {
        return find(banned.begin(), banned.end(), str) == banned.end();
    }

public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        this->banned = banned;

        string cur;
        unordered_map<string, int> freq;
        int maxFreq = -1;
        string maxWord;
        for (int i = 0; i < paragraph.size(); ++i) {
            switch (paragraph[i]) {
                default:
                    cur += tolower(paragraph[i]);
                    break;
                case ' ':
                case '!':
                case '?':
                case '\'':
                case ',':
                case ';':
                case '.': {
                    if (!cur.empty() && isNotBanned(cur)) {
                        freq[cur]++;
                        if (freq[cur] > maxFreq) {
                            maxFreq = freq[cur];
                            maxWord = cur;
                        }
                    }
                    cur = ""; // reset
                    break;
                }
            }
        }

        if (!cur.empty() && isNotBanned(cur)) {
            freq[cur]++;
            if (freq[cur] > maxFreq) {
                maxFreq = freq[cur];
                maxWord = cur;
            }
        }

        return maxWord;
    }
};
