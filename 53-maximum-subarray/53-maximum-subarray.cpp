class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const size_t size = nums.size();
        for (int i = 1; i < size; ++i) {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
        }
        return *max_element(nums.begin(), nums.end());
    }
};
