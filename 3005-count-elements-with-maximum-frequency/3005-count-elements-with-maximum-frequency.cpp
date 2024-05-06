class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        int maxFreq = INT_MIN;
        for (auto [val, f] : freq) {
            maxFreq = max(maxFreq, f);
        }

        int res = 0;
        for (auto [val, f] : freq) {
            if (maxFreq == f) {
                res += maxFreq;
            }
        }
        return res;
    }
};
