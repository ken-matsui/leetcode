class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        auto cmp = [](const auto& lhs, const auto& rhs) {
            if (lhs.first != rhs.first) {
                return lhs.first > rhs.first;
            }
            return lhs.second < rhs.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            pq(cmp);
        for (auto [val, f] : freq) {
            pq.emplace(f, val);
        }

        vector<int> res(nums.size());
        for (int i = 0; i < nums.size() && !pq.empty();) {
            auto [f, val] = pq.top();
            pq.pop();

            for (int j = 0; j < f; ++j) {
                res[i + j] = val;
            }
            i += f;
        }
        return res;
    }
};
