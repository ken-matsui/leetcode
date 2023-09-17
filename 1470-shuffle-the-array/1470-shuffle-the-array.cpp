class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(n * 2);
        for (int i = 0; i < n; ++i) {
            res[i * 2] = nums[i];
        }
        for (int i = n; i < n * 2; ++i) {
            res[(i - n) * 2 + 1] = nums[i];
        }
        return res;
    }
};
