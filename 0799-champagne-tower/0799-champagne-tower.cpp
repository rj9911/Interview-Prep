class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double>(query_row+1,0));
        
        dp[0][0]=poured;
        for(int i=1;i<=query_row;i++)
        { 
            dp[i][0]=dp[i][i]=(dp[i-1][0]-1)/2;    
            for(int j=1;j<i;j++)
            {
                if(dp[i-1][j-1]>1 && dp[i-1][j]>1)
                dp[i][j]=(dp[i-1][j-1]-1)/2+(dp[i-1][j]-1)/2;
                else if(dp[i-1][j-1]>1)
                dp[i][j]=(dp[i-1][j-1]-1)/2;
                else
                dp[i][j]=(dp[i-1][j]-1)/2;
            }
        }
       if(dp[query_row][query_glass]>=1)
       return 1;
       else if(dp[query_row][query_glass]<=0)
       return 0;
       else
       return dp[query_row][query_glass];
    }

};