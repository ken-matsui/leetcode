class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> keys;
        for (int i = 0; i < keyboard.size(); ++i) {
            keys[keyboard[i]] = i;
        }
        
        int pos = 0;
        int ans = 0;
        for (const char w : word) {
            ans += abs(pos - keys[w]);
            pos = keys[w];
        }
        return ans;
    }
};