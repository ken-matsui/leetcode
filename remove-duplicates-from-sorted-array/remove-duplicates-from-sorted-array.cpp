class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto parsed = std::unique(nums.begin(), nums.end());
        return std::distance(nums.begin(), parsed);        
    }
};