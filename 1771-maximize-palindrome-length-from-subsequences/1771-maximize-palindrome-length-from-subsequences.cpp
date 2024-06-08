class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string word = word1 + word2;
        int size1 = word1.size(), size2 = word2.size();
        int size = word.size();
        vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
        int result = 0;
        for(int i = 1; i <= size; ++i) {
            dp[i][i] = 1;
        }
        for(int i = size; i >= 1; --i) {
            for(int j = i + 1; j <= size; ++j) {
                if(word[i - 1] == word[j - 1]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if(i <= size1 && j > size1) {
                        result = max(result, dp[i][j]);
                    } 
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return result;   
    }


};