class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // index
        string cur;
        unordered_map<string, int> freq;
        int maxFreq = -1;
        string maxWord;
        for (int i = 0; i < paragraph.size(); ++i) {
            switch (paragraph[i]) {
                case ' ':
                case '!':
                case '?':
                case '\'':
                case ',':
                case ';':
                case '.': {
                    if (cur.empty()) {
                        continue;
                    }
                    if (find(banned.begin(), banned.end(), cur) == banned.end()) {
                        // not banned -> index
                        freq[cur]++;
                        if (freq[cur] > maxFreq) {
                            maxFreq = freq[cur];
                            maxWord = cur;
                        }
                    }
                    cur = ""; // reset
                    break;
                }
                default:
                    cur += tolower(paragraph[i]);
                    break;
            }
        }
        
        if (!cur.empty()) {
            cout << cur << endl;
            if (find(banned.begin(), banned.end(), cur) == banned.end()) {
                // not banned
                freq[cur]++;
                if (freq[cur] > maxFreq) {
                    maxFreq = freq[cur];
                    maxWord = cur;
                }
            }
        }

        return maxWord;
    }
};
