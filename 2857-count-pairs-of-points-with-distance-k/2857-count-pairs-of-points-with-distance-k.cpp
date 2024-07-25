class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<int, unordered_map<int, int>> dp;
        int ans = 0;
        for (int i = 0; i < coordinates.size(); ++i) {
            for (int j = 0; j <= k; ++j) {
                int x = j ^ coordinates[i][0], y = (k-j) ^ coordinates[i][1];
                if (dp.find(x) != dp.end() && dp[x].find(y) != dp[x].end()) ans += dp[x][y];
            }
            
            ++dp[coordinates[i][0]][coordinates[i][1]];
        }
        
        return ans;
    }

};