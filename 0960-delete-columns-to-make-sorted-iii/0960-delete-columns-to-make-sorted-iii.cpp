class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();

        if(m==1)return 0;
        vector<int> dp(m,1);

        int ans=0;
        for(int i=1;i<m;i++)
        {
            int j=0;
            while(j<i)
            {
                bool flag=1;
                for(int k=0;k<n;k++)
                {
                    if(strs[k][j]>strs[k][i])
                    {
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                    }
                }

                j++;
            }

            ans=max(dp[i],ans);
        }
        return m-ans;
    }

};