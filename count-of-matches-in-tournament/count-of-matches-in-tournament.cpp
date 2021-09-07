class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while (true) {
            if (n == 1) {
                break;
            }
            int divided = n / 2;
            matches += divided;
            n -= divided;
        }
        return matches;
    }
};