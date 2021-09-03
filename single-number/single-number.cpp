class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t size = nums.size();
        for (int i = 0; i < size; ++i) {
            bool appeared_twice = false;
            for (int j = 0; j < size; ++j) {
                if (i == j) {
                    continue;
                }
                if (nums[i] == nums[j]) {
                    appeared_twice = true;
                    break;
                }
            }
            if (!appeared_twice) {
                return nums[i];
            }
        }
        return nums[size - 1];
    }
};