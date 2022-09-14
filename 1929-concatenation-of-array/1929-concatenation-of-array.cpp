class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums);
        std::copy(nums.begin(), nums.end(), std::back_inserter(ans));
        return ans;
    }
};
