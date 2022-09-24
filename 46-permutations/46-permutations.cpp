class Solution {
    size_t size;

public:
    void dfs(vector<int>& nums, int i, vector<vector<int>>& out) {
		if (i == size) {
		    out.emplace_back(nums);
		    return;
		}

		for (int j = i; j < size; ++j) {
		    swap(nums[i], nums[j]);
		    dfs(nums, i + 1, out);
		    swap(nums[i], nums[j]); // revert
		}
    }

    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();

        vector<vector<int>> out;
	    dfs(nums, 0, out);
	    return out;
    }
};
