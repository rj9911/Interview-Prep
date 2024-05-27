class Solution {
public:
vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 1)
            return {nums[0]};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), temp(n, -1);
        int len = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    temp[i] = j;
                }
                if (dp[i] > len) {
                    len = dp[i];
                    idx = i;
                }
            }
        }

        vector<int> ans(len, 0);
        int index = len - 1;
        while (index >= 0) {
            ans[index] = nums[idx];
            idx = temp[idx];
            index--;
        }
        return ans;
    }

};