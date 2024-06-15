class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
    int MOD = 1000000007;

        unordered_map<int,int> m;
        
        for (auto n: nums) m[n]++;

        vector<int> dp(r+1,0);
        dp[0]=1;
        for (auto [k,v]: m){
            vector<int> cp(dp.begin(),dp.end());
            for (int i=0;i<=r;i++){
                if (i>=k) cp[i] = (1LL*(cp[i] + cp[i-k]))%MOD;
            }
            for (int i=r;i>=0;i--){
                if (k>0){
                    dp[i] = (cp[i] - (i-k*(v+1)>=0?cp[i-k*(v+1)]:0)+MOD)%MOD;
                }
                else{
                    long t= (1LL*dp[i]*(v+1))%MOD;
                    dp[i]=t;
                }
            }
        }

        int ans=0;
        for (int i=l;i<=r;i++) ans = (ans + dp[i])%MOD;
        return ans;
        
    }

};