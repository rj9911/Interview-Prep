class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1,n=nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for(int i=1;i<n;++i){
            int next=nums[i-1];
            if(next+1==nums[i]){
                dp[i][0]=1+dp[i-1][0];
                dp[i][0]=max(dp[i][0],dp[i-1][1]);
                dp[i][1]=max(dp[i][1],1+dp[i-1][1]);
            }
            else if(next+2==nums[i]){
                dp[i][0]=max(dp[i][0],1+dp[i-1][1]);
            }
            else if(next==nums[i]){
                dp[i][0]=max(dp[i][0],dp[i-1][0]);
                dp[i][1]=max(dp[i][1],dp[i-1][1]);
                dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
            }
        }
        for(int i=0;i<n;++i){
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        return ans;
    }

};