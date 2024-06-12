class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i][m-1] = 0;
        }
        
        for (int j = m-2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int rightupp = 0, right = 0, rightlow = 0;
                int val = grid[i][j];
                if (i-1 >= 0 && j+1 < m && val < grid[i-1][j+1]) {
                    rightupp = 1 + dp[i-1][j+1];
                }
                if (j+1 < m && val < grid[i][j+1]) {
                    right = 1 + dp[i][j+1];
                }
                if (i+1 < n && j+1 < m && val < grid[i+1][j+1]) {
                    rightlow = 1 + dp[i+1][j+1];
                }
                dp[i][j] = max(rightupp, max(right, rightlow));
            }
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][0]);
        }

        return ans;
    }

};