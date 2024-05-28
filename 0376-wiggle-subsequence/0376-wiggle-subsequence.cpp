class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
  
        vector<pair<int, int> > dp(nums.size(), pair<int, int>{1, 0}); // length, pattern
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j].first + 1 > dp[i].first) {
                    if (nums[i] > nums[j]) {
                        if (dp[j].second == 0 || dp[j].second == -1) {
                            dp[i].first = dp[j].first + 1;
                            dp[i].second = 1;
                        }
                    } 
                    else if (nums[i] < nums[j]) {
                        if(dp[j].second == 0 || dp[j].second == 1) {
                            dp[i].first = dp[j].first + 1;
                            dp[i].second = -1;
                        }
                    }
                }
            }
        }
        return dp[nums.size()-1].first;
    }
};