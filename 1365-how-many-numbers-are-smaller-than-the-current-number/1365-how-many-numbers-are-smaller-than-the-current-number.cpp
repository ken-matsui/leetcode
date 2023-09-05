class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const size_t size = nums.size();
        auto first = nums.begin();
        auto last = nums.end();

        vector<int> ans(size);
        for (int i = 0; i < size; ++i) {
            const int value = nums[i];

            ans[i] = std::count_if(first, last,
                                   [&value](const int x) { return x < value; });
        }
        return ans;
    }
};
