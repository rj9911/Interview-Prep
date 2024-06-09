class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long long int sum = 0;
        for(auto &i: nums){
            sum += i;
        }
        if(nums.size()==1||sum<2*1LL*k){//if sum<2*k return no of possible ans = 0
            return 0;
        }
        /*find no of possible subsequece whose sum < k */
        int i,j,n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<long long int>> dp(n+1,vector<long long int>(k+1,0));
        int mod = 1e9+7;
        for(i = 0; i <= n; i++){
            for(j = 0; j<k;j++){
                if(i==0||j==0)dp[i][j] = 0;
                if(j==0)dp[i][j] = 1;
                if(i>0&&j>0){
                    if(j>=nums[i-1]){
                        dp[i][j] = (dp[i-1][j-nums[i-1]]+dp[i-1][j])%mod;
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        sum = 0;
        for(i = 0; i < k; i++){
            sum = (sum+dp[n][i])%mod;
        }/*here if no of tt = subsequence whose sum < k*/
        long long int pow = 1,y=2;
        k = nums.size();
        while(k){
            if(k&1){
                pow = (pow*y)%mod;
            }
            y = (y*y)%mod;
            k >>= 1;
        }
        return ((pow-2*sum+mod)%mod);/*return total possible ans - 2*tt */
    }

};