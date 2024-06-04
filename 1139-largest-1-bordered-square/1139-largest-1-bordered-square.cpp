class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<pair<int,int>>> dp(r, vector<pair<int,int>>(c,{0,0}));
        
        int mx = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]!=0){
                    
                    dp[i][j].first = i == 0 ? 1 : dp[i-1][j].first+1;
                    dp[i][j].second = j == 0 ? 1 : dp[i][j-1].second+1;
                    
                    int sz = min(dp[i][j].first, dp[i][j].second);
                    while(sz>mx){
                        int p = min(dp[i-sz+1][j].second,dp[i][j-sz+1].first);
                        if(p>=sz)
                            mx = max(mx,sz);
                        sz--;
                    }
                }
            }
        }
            
        return mx*mx;
    }

};