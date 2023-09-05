class Solution {
public:
    string toLowerCase(string s) {
        string out;
        transform(s.cbegin(), s.cend(), back_inserter(out), ::tolower);
        return out;
    }
};
