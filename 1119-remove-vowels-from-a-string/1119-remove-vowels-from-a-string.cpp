class Solution {
public:
    string removeVowels(string s) {
        string ans;
        for (const char c : s) {
            switch (c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    continue;
                default:
                    ans += c;
                    break;
            }
        }
        return ans;
    }
};