class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int size = nums.size();
        if (size == 1) {
            return;
        }

        int left = 0;
        int right = size - 1;
        
        for (int i = 0; i <= right;) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                ++left;
                ++i;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                --right;
            } else {
                ++i;
            }
        }
    }
};
