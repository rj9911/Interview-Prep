class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp (n+1, false);
        if (n<2) {
            return false;
        }
        dp[0] = true;
        dp[1] = false;
        for (int i=2; i<=n ;i++) {
            bool tmp = false;
            if (nums[i-1] == nums[i-2]) {
                tmp = tmp | dp[i-2];
            }
            if (i>=3) {
                if ((nums[i-1] == nums[i-2] && nums[i-1] == nums[i-3]) || (nums[i-1] == nums[i-2] +1 && nums[i-3]+1 == nums[i-2])) {
                    tmp = tmp | dp[i-3];
                }
            }
            dp[i] = tmp;

        }
        
        return dp[n];
    }

};