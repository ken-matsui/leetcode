class Solution {
    int climbStairs(int i, int n, vector<int>& dp) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (dp[i] > 0) {
            return dp[i];
        }
        dp[i] = climbStairs(i + 1, n, dp) + climbStairs(i + 2, n, dp);
        return dp[i];
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        return climbStairs(0, n, dp);
    }
};
