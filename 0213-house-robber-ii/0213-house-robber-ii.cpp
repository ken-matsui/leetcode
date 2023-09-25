class Solution {
    int robRange(const vector<int>& nums, const int start, const int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            int tmp = second;
            second = max(second, first + nums[i]);
            first = tmp;
        }
        return second;
    }

public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};
