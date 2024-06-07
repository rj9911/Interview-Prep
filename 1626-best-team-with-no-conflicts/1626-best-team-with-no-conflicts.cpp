class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> team;
        int n = ages.size();
        for(int i = 0; i < n; i++) {
            team.push_back({scores[i], ages[i]});
        }
        sort(team.begin(), team.end());
        vector<vector<int>> dp(n + 1, vector<int>(1001, 0));
        for(int ind = n - 1; ind >= 0; ind--) {
            for(int prev = 0; prev <= 1000; prev++) {
                int &maxScore = dp[ind][prev];
                maxScore = dp[ind + 1][prev];
                if(team[ind].second >= prev) 
                    maxScore = max(maxScore, team[ind].first + dp[ind + 1][team[ind].second]);
            }
        }
        return dp[0][0];
    }

};