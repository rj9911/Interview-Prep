class Solution {
public:
    int kInversePairs(int n, int k) {
        int maxPossibleInversions = n * (n - 1) / 2;
        if (k > maxPossibleInversions) {
            return 0;
        }
        if (k == 0 || k == maxPossibleInversions) {
            return 1;
        }

        const int MOD = pow(10, 9) + 7;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }

        dp[2][1] = 1;

        for (int i = 3; i <= n; i++) {
            maxPossibleInversions = min(k, i * (i - 1) / 2);
            for (int j = 1; j <= maxPossibleInversions; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
                }
            }
        }

        return dp[n][k];
    }

};