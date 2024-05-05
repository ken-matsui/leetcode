class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int n : nums) {
            cnt[n]++;
        }
        
        const size_t size = nums.size();
        vector<int> res;
        for (auto [val, c] : cnt) {
            if (c > (size/3)) {
                res.push_back(val);
            }
        }
        return res;
    }
};
