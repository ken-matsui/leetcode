class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool inBar = false;
        for (char c : s) {
            if (!inBar && c == '|') {
                inBar = true;
            } else if (inBar && c == '|') {
                inBar = false;
            } else if (!inBar && c == '*') {
                ++count;
            }
        }
        return count;
    }
};