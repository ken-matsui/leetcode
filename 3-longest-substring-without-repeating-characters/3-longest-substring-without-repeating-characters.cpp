class Solution {
    template <typename T, typename U>
    bool contains(const unordered_map<T, U>& m, const T key) {
        if (m.find(key) == m.end()) {
            return false;
        }
        return true;
    }

public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int result = 0;
        unordered_map<char, int> window;
        int start = 0;

        for (int end = 0; end < size; ++end) {
            const char cur = s[end];

            if (contains(window, cur)) {
                if (window[cur] >= start) {
                    start = window[cur] + 1;
                } else {
                    result = max(result, end - start + 1);
                }
            } else {
                result = max(result, end - start + 1);
            }
            window[cur] = end;
        }

        result = max(result, size - start);
        return result;
    }
};
