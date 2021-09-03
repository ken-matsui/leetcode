class Solution {
public:
    bool isPalindrome(string s) {
        size_t size = s.size();
        size_t first = 0;
        size_t last = size - 1;

        for (; first < last; ++first, --last) {
            for (; !isalnum(s[first]) && first < last; ++first);
            if (first >= last) {
                break;
            }
            for (; !isalnum(s[last]) && first < last; --last);
            if (first >= last) {
                break;
            }

            const char fs = std::tolower(s[first]);
            const char ls = std::tolower(s[last]);

            if (fs != ls) {
                return false;
            }
        }
        return true;
    }
};