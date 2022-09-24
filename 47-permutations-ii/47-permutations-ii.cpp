class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const size_t size = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> out;
        do {
            out.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return out;
    }
};
