class Solution {
public:
        int maximalRectangle(vector<vector<char>>& g) {
        int ans = 0 , n = g.size() , m = g[0].size();
        vector<vector<int>> dp(n,vector<int>(m+1,0));
        for(int i=0; i<m; i++) {
            int c = 0;
            for(int j=0; j<n; j++) {
                g[j][i]=='1' ? c++ : c=0;
                dp[j][i]=c;
            }
        }
        for(int i=0; i<n; i++) {
            vector<int> stk;
            for(int j = 0; j<=m; j++) {
                  while(!stk.empty() && dp[i][stk.back()]>=dp[i][j]) {
                           int last = stk.back();
                           stk.pop_back();
                           int sc = stk.empty() ? -1 : stk.back();
                           ans = max(ans,(j - 1 - sc)*dp[i][last]);
                  }
                  stk.push_back(j);
            }
        }
        return ans;
    }

};