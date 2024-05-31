class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1; // Base case: single character is a palindrome
        }

        const long long MOD = 1e9 + 7;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] != s[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                } else {
                    int next = i + 1;
                    int prev = j - 1;

                    while (next <= prev && s[next] != s[i]) {
                        next++;
                    }
                    while (next <= prev && s[prev] != s[i]) {
                        prev--;
                    }

                    if (next > prev) {
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 2) % MOD;
                    } else if (next == prev) {
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 1) % MOD;
                    } else {
                        dp[i][j] = (2 * dp[i + 1][j - 1] - dp[next + 1][prev - 1] + MOD) % MOD;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }

};