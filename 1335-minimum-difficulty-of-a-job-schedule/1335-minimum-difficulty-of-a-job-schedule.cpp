class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int sz = jobDifficulty.size();
        if (d > sz) return -1;
        vector<int> dp(sz + 1, 1e5);
        dp[sz-1] = jobDifficulty[sz-1];
        for(int i = sz - 2; i >= 0; i--) dp[i] = max(dp[i+1], jobDifficulty[i]);
        for (int j = 2; j <= d; j++){
            for (int i = 0; i <= sz - j; i++){
                dp[i] = 1e5;
                int maxValue = jobDifficulty[i];
                for (int k = i; k <= sz - j; k++){
                    maxValue = max(maxValue, jobDifficulty[k]);
                    dp[i] = min(dp[i], maxValue + dp[k+1]);
                }
            }
        }
        return dp[0];
    }

};