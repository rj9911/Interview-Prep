class Solution {
public:
int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp;
        int sum = 0;
        for(auto rod: rods) {
            sum += rod;
        }

        dp.resize(rods.size());
        for(int i = 0; i < dp.size(); i++) {
            dp[i].resize(2 * sum + 1);
            for(int j = 0; j < 2 * sum + 1; j++) {
                dp[i][j] = -1;
            }
        }

        for(int i = 0; i < rods.size(); i++) {
            if (i == 0) {
                dp[i][sum + rods[i]] = rods[i];
                dp[i][sum - rods[i]] = 0;
                dp[i][sum] = 0;
            } else {
                for(int j = 0; j < 2 * sum + 1; j++) {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= rods[i] && dp[i - 1][j - rods[i]] > -1) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - rods[i]] + rods[i]);
                    }
                    if (j + rods[i] < dp[i - 1].size() && dp[i - 1][j + rods[i]] > -1) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j + rods[i]]);
                    }
                }
            }
        }
        return dp[dp.size() - 1][sum];
    }

};