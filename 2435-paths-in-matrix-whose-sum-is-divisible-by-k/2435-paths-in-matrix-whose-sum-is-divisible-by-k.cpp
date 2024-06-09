class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (k, 0)));
        dp[0][1][0] = 1;
        int i, j, r, s, mod = 1e9 + 7;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                for(r = 0; r < k; r++) {
                    s = (r + grid[i][j]) % k;
                    dp[i + 1][j + 1][s] = (dp[i][j + 1][r] + dp[i + 1][j][r]) % mod;
                }
            }
        }
        return dp[n][m][0];
    }

};