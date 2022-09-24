class Solution {
public:
    string longestPalindrome(string s) {
        const size_t size = s.size();
        if (size <= 1) {
            return s;
        }

        int start = 0;
        int maxLen = 1;
        for (int i = 0; i < size; ) {
            int left = i;
            int right = i;
            // Duplicate characters are all palindromic.
            // b, bb, bbb, bbbb, ...
            for (; right < size - 1 && s[right] == s[right + 1]; ++right);
            i = right + 1;
            for (; right < size - 1 && left > 0 && s[right + 1] == s[left - 1]; ++right, --left);

            const int curLen = right - left + 1;
            if (maxLen < curLen) {
                start = left;
                maxLen = curLen;
            }
        }
        return s.substr(start, maxLen);
    }
};
