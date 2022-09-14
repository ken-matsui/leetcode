class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        const size_t size = nums.size();
        vector<int> ans;

        for (int x = 0, y = n; x < n && y < size; ++x, ++y) {
            ans.push_back(nums[x]);
            ans.push_back(nums[y]);
        }

        return ans;
    }
};
