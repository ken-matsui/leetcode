class Solution {
    vector<vector<optional<bool>>> dp;
    
    bool dfs(const vector<int>& nums, const int n, const int subsetSum) {
        if (subsetSum == 0) {
            return true;
        }
        if (n == 0 || subsetSum < 0) {
            return false;
        }
        if (dp[n][subsetSum] != nullopt) {
            return (dp[n][subsetSum] == true);
        }
        bool res = dfs(nums, n - 1, subsetSum - nums[n - 1]) 
            || dfs(nums, n - 1, subsetSum);
        dp[n][subsetSum] = res;
        return res;
    }

public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return false;
        }

        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

        const int subsetSum = sum / 2;
        dp = vector<vector<optional<bool>>>(n + 1, vector<optional<bool>>(subsetSum + 1, nullopt));
        return dfs(nums, n - 1, subsetSum);
    }
};
