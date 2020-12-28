class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int c = 0;
        for (const auto j : J) {
            c += count(S.cbegin(), S.cend(), j);
        }
        return c;
    }
};
​
