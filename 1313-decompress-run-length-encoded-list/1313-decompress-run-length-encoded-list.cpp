class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;

        const size_t size = nums.size();
        for (int i = 0; i < size; i += 2) {
            const int freq = nums[i];
            const int val = nums[i + 1];

            for (int j = 0; j < freq; ++j) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};
