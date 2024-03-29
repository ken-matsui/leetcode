class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const size_t size = nums.size();

        vector<int> ans(size);
        for (int i = 0; i < size; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
