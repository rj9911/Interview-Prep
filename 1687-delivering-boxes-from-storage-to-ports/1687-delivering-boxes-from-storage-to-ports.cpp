class Solution {
public:
    int boxDelivering(vector<vector<int>>& a, int portsCount, int mxb, int mxw) 
    {
        int n=a.size();
        bool add[n+5]; memset(add,0,sizeof(add));
        for(int i=0;i<n-1;i++)
            if(a[i][0]!=a[i+1][0])
                add[i]=1;
        
        int w=0,j=0,trip=0,dp[n+5]; memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            w+=a[i][1];
            if(i) trip+=add[i-1];
            
            while(i-j>=mxb)
                w-=a[j][1],trip-=add[j],j++;
            
            while(w>mxw)
                w-=a[j][1],trip-=add[j],j++;
            
            while(j<i && dp[j]==dp[j+1])
                w-=a[j][1],trip-=add[j],j++;
            
            dp[i+1]=dp[j]+trip+2;
        }
        return dp[n];
    }

};