class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] != 0) {
                continue;
            }

            // found 0; check if we can skip this 0
            bool canSkip = false;
            int reqToSkip = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] > reqToSkip) {
                    // can skip this 0
                    canSkip = true;
                }
                ++reqToSkip;
            }
            if (!canSkip) {
                return false;
            }
        }
        return true;
    }
};
