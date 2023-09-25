class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> freq;
        for (const char c : s) {
            freq[c]++;
        }

        int oddCount = 0;
        for (const auto& [k, v] : freq) {
            if (v % 2 != 0) {
                ++oddCount;
            }
        }
        return oddCount <= 1;
    }
};
