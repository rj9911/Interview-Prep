class Solution {
public:
    #define ll long long
const int mod = 1e9 + 7;
    int stringCount(int n) {
        // dp vector initialised with 0's.
        vector<vector<vector<vector<ll>>>> dp(n + 1, vector<vector<vector<ll>>> (2, vector<vector<ll>> (3, vector<ll> (2, 0))));

        // Base Case: One string of len 0 with 0 'l', 0 'e' and 0 't'.
        dp[0][0][0][0] = 1;

        // Dynamic Programming to fill the dp vector.
        for (int i = 0; i < n; ++i) {
            for (int p = 0; p < 2; ++p) {
                for (int q = 0; q < 3; ++q) {
                    for (int r = 0; r < 2; ++r) {
                        dp[i + 1][p][q][r] = (dp[i + 1][p][q][r] + dp[i][p][q][r] * 23) % mod;
                        dp[i + 1][min(1, p + 1)][q][r] = (dp[i + 1][min(1, p + 1)][q][r] + dp[i][p][q][r]) % mod;
                        dp[i + 1][p][min(2, q + 1)][r] = (dp[i + 1][p][min(2, q + 1)][r] + dp[i][p][q][r]) % mod;
                        dp[i + 1][p][q][min(1, r + 1)] = (dp[i + 1][p][q][min(1, r + 1)] + dp[i][p][q][r]) % mod;
                    }
                }
            }
        }

        // The result is the count of the strings of length n having 1 'l', 2 'e' and 1 't'.
        return (int)dp[n][1][2][1];
    }

};