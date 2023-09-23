class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;

        unordered_map<char, int> chars;
        int res = 0;
        while (right < s.length()) {
            const char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                const char l = s[left];
                chars[l]--;
                ++left;
            }
            res = max(res, right - left + 1);
            ++right;
        }
        return res;
    }
};
