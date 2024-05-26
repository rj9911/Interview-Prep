class Solution {
public:

    int numDistinct(string s, string t) {

        const int MOD = 1e9 + 7;

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));   
        for (int sIndex = 0; sIndex <= n; ++sIndex) {
            dp[sIndex][m] = 1;
        }

        for (int sIndex = n - 1; sIndex >= 0; --sIndex) {
            for (int tIndex = m - 1; tIndex >= 0; --tIndex) {
                int res = 0;
                if (s[sIndex] == t[tIndex]) {
                    res += dp[sIndex + 1][tIndex + 1] % MOD;
                }
                res += dp[sIndex + 1][tIndex] % MOD;
                dp[sIndex][tIndex] = res;
            }
        }
        
        return dp[0][0];
    }

};