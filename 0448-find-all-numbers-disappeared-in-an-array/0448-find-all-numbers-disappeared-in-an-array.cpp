class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        vector<int> res;
        for (int i = 1; i <= nums.size(); ++i) {
            if (!s.contains(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};