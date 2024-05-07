class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                s.insert(i);
            }
        }

        set<int> s2;
        for (int idx : s) {
            for (int i = 0; i < nums.size(); ++i) {
                if (abs(i - idx) <= k) {
                    s2.insert(i);
                }
            }
        }

        vector<int> res;
        for (int i : s2) {
            res.push_back(i);
        }
        return res;
    }
};
