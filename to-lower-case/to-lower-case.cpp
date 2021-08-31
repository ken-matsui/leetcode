class Solution {
public:
    string toLowerCase(string str) {
        string out;
        transform(str.cbegin(), str.cend(),  back_inserter(out), ::tolower);
        return out;
    }
};
​
