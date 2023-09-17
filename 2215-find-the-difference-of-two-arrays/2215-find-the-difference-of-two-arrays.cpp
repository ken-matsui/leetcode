class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> one(nums1.begin(), nums1.end());
        unordered_set<int> two(nums2.begin(), nums2.end());
        
        vector<vector<int>> res(2);
        for (const int n : one) {
            if (two.find(n) == two.end()) {
                res[0].push_back(n);
            }
        }
        for (const int n : two) {
            if (one.find(n) == one.end()) {
                res[1].push_back(n);
            }
        }
        return res;
    }
};
