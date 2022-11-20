class Solution {
    size_t size;
    vector<vector<int>> out;
    vector<int> tmp;

    void backtrack(const vector<int>& nums, const int start) {
        out.emplace_back(tmp);
        for (int i = start; i < size; ++i) {
            tmp.emplace_back(nums[i]);
            backtrack(nums, i + 1);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        backtrack(nums, 0);
        return out;
    }
};
