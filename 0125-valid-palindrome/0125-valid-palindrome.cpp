class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }

        const int size = str.size();
        const string left = str.substr(0, size / 2);
        string right = str.substr(size / 2 + (size % 2));
        reverse(right.begin(), right.end());
        return left == right;
    }
};
