class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }

        int numPairs = 0;
        int numLeftover = 0;
        for (auto [val, freq] : m) {
            numPairs += freq / 2;
            numLeftover += freq % 2;
        }
        return {numPairs, numLeftover};
    }
};