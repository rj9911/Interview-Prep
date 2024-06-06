class Solution {
public:
    int minDistance(vector<int>& houses, int k)
    {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<int>> bp(n, vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ans1 = 0;
                for(int x=i;x<=j;x++){ans1+=abs(houses[x]-houses[(i+j)/2]);}
                int ans2 = 0;
                for(int x=i;x<=j;x++){ans2+=abs(houses[x]-houses[(i+j)/2+(1)]);}
                bp[i][j]=min(ans1, ans2);
            }
        }
        vector<vector<int>> dp(n, vector<int>(k+1));
        for(int i=0;i<n;i++){dp[i][0]=2e9;}
        for(int i=0;i<n;i++){dp[i][1]=bp[0][i];}
        for(int i=1;i<n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                int val = 2e9;
                for(int x=0;x<=i-1;x++)
                {
                    val=min(val, dp[x][j-1]+bp[x+1][i]);
                }
                dp[i][j]=val;
            }
        }
        return dp[n-1][k];    
    }

};