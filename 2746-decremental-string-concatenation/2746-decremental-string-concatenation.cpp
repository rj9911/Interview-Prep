class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int dp[1000][26][26];
        int n = words.size();

        // clear
        for (int i = 0; i <n; i++) {
            for (int j = 0; j <26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i][j][k] = 50000;
                }
            }
        }

        dp[0][words[0][0] - 'a'][words[0][words[0].size() - 1] - 'a'] = words[0].size();

        for (int i = 1; i < n; i++) {
            int l = words[i].size();
            int firstChar = words[i][0] - 'a';
            int lastChar = words[i][l - 1] - 'a';

            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i][firstChar][j] = min(dp[i][firstChar][j], dp[i - 1][k][j] + l - (k == lastChar ? 1 : 0));
                    dp[i][j][lastChar] = min(dp[i][j][lastChar], dp[i - 1][j][k] + l - (k == firstChar ? 1 : 0));
                }
            }
        }

        int ans = 50000;
        int firstChar = words[n - 1][0] - 'a';
        int lastChar = words[n - 1][words[n - 1].size() - 1] - 'a';
        for (int i = 0; i < 26; i++) {
            ans = min(ans, dp[n - 1][firstChar][i]);
            ans = min(ans, dp[n - 1][i][lastChar]);
        }

        return ans;

    }

};