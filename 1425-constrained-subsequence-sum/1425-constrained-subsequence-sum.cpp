class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k)
    {
        int n=nums.size();
        int ans=-10000;
        int dp[n+1];
        
        dp[0]=nums[0];
        for(int i=0;i<n;i++)
        {
            dp[i]=nums[i];
            ans=max(ans,dp[i]);
        }
        priority_queue<pair<int,int>>pq;
        pq.push(make_pair(nums[0],0));
        for(int i=1;i<n;i++)
        {
            while(i-pq.top().second>k)
            {
                pq.pop();
            }
            dp[i]=max(dp[i],nums[i]+pq.top().first);
            pq.push(make_pair(dp[i],i));
            ans=max(ans,dp[i]);
        }
        return ans;
        
        
        
        
    }

};