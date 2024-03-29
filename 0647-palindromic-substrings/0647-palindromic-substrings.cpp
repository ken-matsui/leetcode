class Solution {
    int expandAroundCenter(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            ++count; // Found a palindrome substring
            --left;  // Expand to the left
            ++right; // Expand to the right
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += expandAroundCenter(s, i, i);     // Odd length palindromes
            count += expandAroundCenter(s, i, i + 1); // Even length palindromes
        }
        return count;
    }
};
