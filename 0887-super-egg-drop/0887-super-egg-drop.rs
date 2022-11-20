impl Solution {
    pub fn super_egg_drop(k: i32, n: i32) -> i32 {
        let K = k as usize;
        let N = n as usize;

        let mut dp = vec![vec![0i32; K + 1]; N + 1];
        let mut m = 0usize;
        while dp[m][K] < n {
            m += 1;
            for k in 1..=K {
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
            }
        }
        return m as i32;
    }
}
