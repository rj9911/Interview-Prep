class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n<=2)
        return true;
        vector<int> prefix(n,0);
        for(int i=0;i<nums.size();i++){
            if(i==0){
                prefix[i]=nums[i];
            } else {
                prefix[i]=prefix[i-1]+nums[i];
            }
        }

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            if(i!=n-1 && nums[i]+nums[i+1]>=m)
            dp[i][i+1]=true;
        }

        for(int len=3;len<=n;len++){
            for(int start=0;start<=n-len;start++){
                int end = start+len-1;
                if(prefix[end]-prefix[start]>=m && dp[start+1][end]) {
                    dp[start][end]= true;
                }
                else if(prefix[end-1]>=m && dp[start][end-1]) {
                    dp[start][end] = true;
                }
            }
        }

        return dp[0][n-1];

    }

};