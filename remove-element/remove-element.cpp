class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto parsed = std::remove_if(
            nums.begin(),
            nums.end(),
            [&val](int a){ return a == val; }
        );
        return std::distance(nums.begin(), parsed);
    }
};