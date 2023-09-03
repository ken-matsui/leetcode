class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        unordered_map<int, int> freq;
        
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            const int n = nums[i];
            
            if (left.find(n) == left.end()) {
                left[n] = i;
            }
            right[n] = i;
            freq[n]++;
            if (maxFreq < freq[n]) {
                maxFreq = freq[n];
            }
        }

        int res = nums.size();
        for (const auto [k, v] : freq) {
            if (v == maxFreq) {
                res = min(res, right[k] - left[k] + 1);
            }
        }
        return res;
    }
};
