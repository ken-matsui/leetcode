class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto n : nums) {
            m[n]++;
        }

        priority_queue<pair<int, int>> pq;
        for (const auto& [n, freq] : m) {
            pq.emplace(freq, n);
        }
 
        vector<int> res;
        while (k--) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
