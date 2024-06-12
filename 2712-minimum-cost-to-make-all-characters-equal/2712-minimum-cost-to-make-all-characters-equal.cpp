class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 1e9));
        vector<vector<long long>> dp2 = dp;
        if(s[0] == '0'){
            dp[0][0] = 0;
            dp[0][1] = 1;
        }else{
            dp[0][0] = 1;
            dp[0][1] = 0;
        }
        
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                dp[i][0] = min({dp[i - 1][0], dp[i - 1][1] + i});
                dp[i][1] = min({dp[i - 1][1] + 2 * i + 1, dp[i - 1][0] + i + 1});
            }else{
                dp[i][0] = min({dp[i - 1][0] + 2 * i + 1, dp[i - 1][1] + i + 1});
                dp[i][1] = min({dp[i - 1][1], dp[i - 1][0] + i});
            }
        }
        
        reverse(s.begin(), s.end());
        if(s[0] == '0'){
            dp2[0][0] = 0;
            dp2[0][1] = 1;
        }else{
            dp2[0][0] = 1;
            dp2[0][1] = 0;
        }
        
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                dp2[i][0] = min({dp2[i - 1][0], dp2[i - 1][1] + i});
                dp2[i][1] = min({dp2[i - 1][1] + 2 * i + 1, dp2[i - 1][0] + i + 1});
            }else{
                dp2[i][0] = min({dp2[i - 1][0] + 2 * i + 1, dp2[i - 1][1] + i + 1});
                dp2[i][1] = min({dp2[i - 1][1], dp2[i - 1][0] + i});
            }
        }
        reverse(dp2.begin(), dp2.end());
        long long ans = 1e12;
        for(int i = 0; i < n - 1; i++){
            ans = min({ans, dp[i][0] + dp2[i + 1][0], dp[i][1] + dp2[i + 1][1]});
        }
        
        return (ans == 1e12 ? 0 : ans);
    }

};