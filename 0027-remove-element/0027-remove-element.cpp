class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size() - 1;
        while (right >= 0 && nums[right] == val) {
            --right;
        }
        if (right < 0) {
            // everything was val
            return 0;
        }

        for (int i = 0; i < right;) {
            if (nums[i] == val) {
                swap(nums[i], nums[right]);
                while (right > i && nums[right] == val) {
                    --right;
                }
            } else {
                ++i;
            }
        }

        return right + 1;
    }
};
