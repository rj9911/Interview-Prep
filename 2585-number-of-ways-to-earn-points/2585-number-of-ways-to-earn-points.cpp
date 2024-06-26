class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size(), mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        for(int i=0; i<=n; i++) dp[i][0] = 1;

        for(int i=n-1; i>=0; i--) {
            for(int t=target; t>=0; t--) {
                long long ans = 0;
                for(int j=0; j<=types[i][0] * types[i][1]; j += types[i][1]) {
                    if(t - j >= 0) ans = (ans + dp[i + 1][t - j]) % mod;
                }
                dp[i][t] = ans;
            }
        }
        return dp[0][target];
    }

};