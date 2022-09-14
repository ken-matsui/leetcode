class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int c = 0;
        for (const auto j : jewels) {
            c += count(stones.cbegin(), stones.cend(), j);
        }
        return c;
    }
};
