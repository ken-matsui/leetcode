class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int nsize = nums.size();
        for (int i = 0; i < nsize; ++i) {
            for (int j = i + 1; j < nsize; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
