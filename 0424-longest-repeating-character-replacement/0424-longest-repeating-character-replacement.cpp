class Solution {
    bool isWindowValid(int start, int end, int count, int k) {
        return end + 1 - start - count <= k;
    }

public:
    int characterReplacement(string s, int k) {
        unordered_set<char> chars(s.begin(), s.end());

        int maxLen = 0;
        for (const char c : chars) {
            int start = 0;
            int count = 0;
            for (int end = 0; end < s.size(); ++end) {
                if (s[end] == c) {
                    ++count;
                }

                while (!isWindowValid(start, end, count, k)) {
                    if (s[start] == c) {
                        --count;
                    }
                    ++start;
                }
                maxLen = max(maxLen, end + 1 - start);
            }
        }
        return maxLen;
    }
};
