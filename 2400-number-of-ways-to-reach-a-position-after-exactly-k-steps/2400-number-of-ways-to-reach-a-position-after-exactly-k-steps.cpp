class Solution {
public:
#define ll long long
    int numberOfWays(int startpos, int endpos, int k)
    {
        vector<vector<ll>> dp(k + k + 2, vector<ll>(k + 1));  //dp[i][j] denotes ways we can reach ith position in j moves
		//k + k + 2 coz we can go as low as starpos - k and as high as startpos + k
		
        if (startpos + k < endpos) // means we can't reach endpos even with k moves
            return 0;
        dp[k][0] = 1; //dp[0] is actually startpos - k th position, that makes dp[k] startpos. 
		//dp[k][0] means we start at startpos with 0 moves and there's 1 way for this.
        int INF = 1e9 + 7; //MOD
        for (int j = 0; j < k; j++)
        {
            for (int i = 0; i < 2 * k + 2; i++)
            {
                if (i + 1 < 2 * k + 2)
                {
                    dp[i + 1][j + 1] += dp[i][j]; //going i+1 from i in 1 move
                    dp[i + 1][j + 1] %= INF;
                }
                if (i - 1 >= 0)
                {
                    dp[i - 1][j + 1] += dp[i][j]; //going i - 1 from i in 1 move
                    dp[i - 1][j + 1] %= INF;
                }
            }
        }
        return dp[endpos - startpos + k][k]; // since dp[k] is startpos, dp[k + (endpos - startpos)] is endpos.
		// dp[k + (endpos - startpos)][k] is ways to reach endpos with k moves.
    }
};