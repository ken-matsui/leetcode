class Solution {
public:
    void dfs(vector<int>& nums, const int i, vector<vector<int>>& out) {
		if (i == nums.size()) {
		    out.emplace_back(nums);
		    return;
		}

		for (int j = i; j < nums.size(); ++j) {
		    swap(nums[i], nums[j]);
		    dfs(nums, i + 1, out);
		    swap(nums[i], nums[j]); // revert
		}
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
	    dfs(nums, 0, out);
	    return out;
    }
};
