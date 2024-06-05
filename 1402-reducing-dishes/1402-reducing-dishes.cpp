class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 2));

        for(int i=n-1; i>=0; i--) {
            for(int cnt=1; cnt<=n; cnt++) {
                int notpick = 0 + dp[i + 1][cnt];
                int pick = satisfaction[i] * cnt + dp[i + 1][cnt + 1];
                dp[i][cnt] = max(pick, notpick);
            } 
        }
        return dp[0][1];
    }
};