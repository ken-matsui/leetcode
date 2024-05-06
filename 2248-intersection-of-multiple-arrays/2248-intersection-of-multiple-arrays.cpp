class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        if (nums.size() == 1) {
            sort(nums[0].begin(), nums[0].end());
            return nums[0];
        }

        vector<unordered_set<int>> vs;
        for (int i = 1; i < nums.size(); ++i) {
            unordered_set<int> s;
            for (int n : nums[i]) {
                s.insert(n);
            }
            vs.push_back(s);
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : nums[0]) {
            bool all_contains = true;
            for (const auto& s : vs) {
                if (!s.contains(n)) {
                    all_contains = false;
                    break;
                }
            }
            if (all_contains) {
                pq.push(n);
            }
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};