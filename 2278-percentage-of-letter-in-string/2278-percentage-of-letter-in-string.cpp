class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (char c : s) {
            if (c == letter) {
                ++count;
            }
        }
        if (count == 0) {
            return 0;
        }
        return ((double)count / (double)s.size()) * 100;
    }
};
