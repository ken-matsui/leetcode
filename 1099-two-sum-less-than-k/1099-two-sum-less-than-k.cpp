class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int maxVal = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j >= k) {
                    continue;
                }
                if (nums[i] + nums[j] < k && maxVal < nums[i] + nums[j]) {
                    maxVal = nums[i] + nums[j];
                }
            }
        }
        return maxVal;
    }
};
