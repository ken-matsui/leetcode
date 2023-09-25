class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int maxVal = nums[0];
        int minVal = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(minVal, maxVal);
            }
            maxVal = max(nums[i], maxVal * nums[i]);
            minVal = min(nums[i], minVal * nums[i]);
            res = max(res, maxVal);
        }
        return res;
    }
};
