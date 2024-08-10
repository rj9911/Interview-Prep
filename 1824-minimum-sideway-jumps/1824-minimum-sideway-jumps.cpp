class Solution {
public:
    int minSideJumps(vector<int> &obstacles){
            int n = obstacles.size();
            vector<vector < int>> dp(n, vector<int> (3, 1e9));
            for (int i = 0; i <= 2; i++) dp[n - 1][i] = 0;

            for (int idx = n - 2; idx >= 0; idx--){
                for (int currLane = 0; currLane <= 2; currLane++){
                    if (obstacles[idx+1] != currLane +1) dp[idx][currLane] = dp[idx + 1][currLane];
                    else
                    {
                        int mn = 1e9;
                        for (int i = 0; i <= 2; i++){
                            if (i != currLane && obstacles[idx] != i + 1){
                                mn = min(mn, 1 + dp[idx + 1][i]);
                            }
                        }
                        dp[idx][currLane] = mn;
                    }
                }
            }
            return min(dp[0][1], 1 + min(dp[0][0], dp[0][2]));
    }

};