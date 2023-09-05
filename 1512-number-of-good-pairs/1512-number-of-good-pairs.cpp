class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        const size_t size = nums.size();

        int count = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] == nums[j]) {
                    ++count;
                }
            }
        }
        return count;
    }
};
