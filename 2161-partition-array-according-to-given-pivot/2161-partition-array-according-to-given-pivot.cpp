class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> middle;
        vector<int> right;

        const size_t size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] < pivot) {
                left.emplace_back(nums[i]);
            } else if (nums[i] == pivot) {
                middle.emplace_back(nums[i]);
            } else {
                right.emplace_back(nums[i]);
            }
        }

        left.insert(left.end(), middle.cbegin(), middle.cend());
        left.insert(left.end(), right.cbegin(), right.cend());
        return left;
    }
};
