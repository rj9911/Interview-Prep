class Solution {
public:
 
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        map<int,set<int>> dp;
        for(int i=0;i<n;i++)
        {
            set<int> s;
            dp[stones[i]]=s;
        }
        dp[stones[0]].insert(1);

        for(int i=0;i<n;i++)
        {
            set<int>s=dp[stones[i]];
            for(auto x: s)
            {
                int t=x+stones[i];
                if(dp.find(t)!=dp.end())
                {
                    for(int j=-1;j<=1;j++)
                    {
                        if(x+j>0)
                        {
                        dp[t].insert(x+j);
                        }
                    }
                }
            }
        }

        return dp[stones[n-1]].size();
    }

};