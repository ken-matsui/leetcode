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
        unordered_map<char, int> seen;
        int start = 0;

        for (int end = 0; end < size; ++end) {
            const char cur = s[end];

            if (contains(seen, cur)) {
                if (seen[cur] >= start) {
                    start = seen[cur] + 1;
                } else {
                    result = max(result, end - start + 1);
                }
            } else {
                result = max(result, end - start + 1);
            }
            seen[cur] = end;
        }

        result = max(result, size - start);
        return result;
    }
};
