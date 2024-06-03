class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        //Scanning from topLeft -> BottomRight
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) continue;
                int up = (i-1>=0)? dp[i-1][j] : INT_MAX;
                int left = (j-1>=0)? dp[i][j-1] : INT_MAX;
                int mn = min(up,left);
                int res = (mn==INT_MAX)? INT_MAX : 1+mn;
                dp[i][j] = res;
            }
        }

        //Scanning from bottomRight -> TopLeft
        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] == 1) continue;
                int down = (i+1<=n-1)? dp[i+1][j] : INT_MAX;
                int right = (j+1<=n-1)? dp[i][j+1] : INT_MAX;
                int mn = min(down, right);
                int res = (mn==INT_MAX)? INT_MAX : 1+mn;
                dp[i][j] = min(dp[i][j], res);
            }
        }

        //Finding the maximumD
        int ans = 0;
        for(auto r:dp) {
            for(int c:r) {
                ans = max(ans, c);
            }
        }
        if(ans==0 || ans==INT_MAX) ans = -1;

        return ans;
    }

};