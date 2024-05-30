class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto s: nums) {
            sum +=s;
        }
        if(target > sum || target < -sum) {
            return 0;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(2*sum + 1, 0));
        int tr = sum ;
        int ntarget = target + tr;

        dp[0][tr - nums[0]] += 1;
        dp[0][tr + nums[0]] += 1;

        for(int i=1; i < nums.size(); i++) {
            for(int k = 0; k <= 2*sum; k++) {
                if(k - nums[i] >= 0) {
                    dp[i][k] +=  dp[i-1][k - nums[i]];
                }
                if(k + nums[i] <= 2*sum) {
                    dp[i][k] +=  dp[i-1][k + nums[i]];
                }
            }
        }

        return dp[nums.size() - 1][ntarget];
    }

};