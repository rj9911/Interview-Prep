class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n+1][k+1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = 1e9;
            }
        }
        
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                int cnt = 0;
                for(int h = i; h >= 1; h--){
                    cnt += nums[h-1];
                    dp[i][j] = min(dp[i][j], max(dp[h-1][j-1], cnt));
                }
                dp[i][j] = min(dp[i][j], max(dp[i-1][j-1], nums[i-1]));
            }
        }
        return dp[n][k];
    }

};