class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto found = std::find_if(nums.begin(), nums.end(),
                                  [&target](int x) { return x >= target; });
        return std::distance(nums.begin(), found);
    }
};
