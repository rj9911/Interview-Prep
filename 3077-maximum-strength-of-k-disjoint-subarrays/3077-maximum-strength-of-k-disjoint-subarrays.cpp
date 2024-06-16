class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        long long n = nums.size();
        
        vector<long long> pre_sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }
        
        vector<vector<long long>> dp1(n + 1, vector<long long>(k + 1, LLONG_MIN));
        vector<vector<long long>> dp2(n + 1, vector<long long>(k + 1, LLONG_MIN));

        for (long long i = 0; i <= n; ++i) {
            dp1[i][0] = dp2[i][0] = 0;
        }

        for (long long i = n - 1; i >= 0; --i) 
        {
            for (long long j = 1; j <= min((long long)k, n - i); ++j) {     
                long long multiplier = (j % 2 == 1) ? 1 : -1;
               
                dp1[i][j] = max({dp1[i + 1][j], dp1[i + 1][j - 1], dp2[i + 1][j - 1]}) + static_cast<long long>(nums[i]) * static_cast<long long>(multiplier) * j;


                dp2[i][j] = max(dp1[i][j], dp2[i + 1][j]);
            }
        }

        return max(dp1[0][k], dp2[0][k]);
    }

};