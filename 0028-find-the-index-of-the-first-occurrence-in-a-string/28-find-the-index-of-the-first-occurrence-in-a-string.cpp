class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty() && needle.empty()) {
            return 0;
        } else if (haystack.empty()) {
            return -1;
        }
        
        auto found = haystack.find(needle);
        if (found == string::npos) {
            return -1;
        }
        return found;
    }
};
