class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto [f, s] = equal_range(nums.begin(), nums.end(), target);
        return distance(f, s) > (nums.size()/2);
    }
};