class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const size_t size = nums.size();
        
        vector<int> ans(size);
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j >= 0; --j) {
                sum += nums[j];
            }
            ans[i] = sum;
        }
        return ans;
    }
};