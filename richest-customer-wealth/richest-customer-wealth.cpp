class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (const auto& a : accounts) {
            const int sum = std::accumulate(a.begin(), a.end(), 0);
            if (max < sum) {
                max = sum;
            }
        }
        return max;
    }
};