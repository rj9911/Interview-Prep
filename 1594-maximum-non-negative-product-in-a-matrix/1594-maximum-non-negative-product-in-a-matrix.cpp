class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),mod=1000000007;
        vector<vector<vector<long long>>> dp(r,vector<vector<long long>>(c,vector<long long>(2,0)));
        dp[0][0][0]=grid[0][0];
        dp[0][0][1]=grid[0][0];

        for(int i=1;i<r;i++) dp[i][0][0]=grid[i][0]*dp[i-1][0][0],dp[i][0][1]=grid[i][0]*dp[i-1][0][0];
        for(int i=1;i<c;i++) dp[0][i][0]=grid[0][i]*dp[0][i-1][0],dp[0][i][1]=grid[0][i]*dp[0][i-1][0];

        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if (grid[i][j]>0){
                    dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0])*grid[i][j];
                    dp[i][j][1]=min(dp[i-1][j][1],dp[i][j-1][1])*grid[i][j];
                }
                else if(grid[i][j]<0){
                    dp[i][j][0]=min(dp[i-1][j][1],dp[i][j-1][1])*grid[i][j];
                    dp[i][j][1]=max(dp[i-1][j][0],dp[i][j-1][0])*grid[i][j];
                }
                else{
                    dp[i][j][1]=0;
                    dp[i][j][0]=0;
                }
            }
        }

        int ans= dp[r-1][c-1][0]%mod;
        return ans<0?-1:ans;
    }

};