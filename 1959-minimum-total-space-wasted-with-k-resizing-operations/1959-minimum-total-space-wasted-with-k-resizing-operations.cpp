class Solution {
public:
int minSpaceWastedKResizing(vector<int>& nums, int k_) {
	vector<vector<int>> dp(nums.size(), vector<int>(k_ + 1, INT_MAX));

	for (int i = 0, maxL = 0, sumL = 0; i < nums.size(); ++i) {
		// k == 0
		maxL = max(maxL, nums[i]);
		sumL += nums[i];
		dp[i][0] = maxL * (i + 1) - sumL;

		for (int k = 1; k <= k_; ++k) {
			dp[0][k] = 0;
			for (int j = i, maxR = 0, sumR = 0; j > 0; --j) {
				maxR = max(maxR, nums[j]);
				sumR += nums[j];
				int wasteR = maxR * (i - j + 1) - sumR;
				dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + wasteR);
			}
		}
	}

	return dp.back().back();
}

};