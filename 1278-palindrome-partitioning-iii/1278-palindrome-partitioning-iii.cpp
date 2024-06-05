class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size() ;
        int changes[n][n] ;
        for(int l = n-1; l >= 0; --l)
        {
            for(int r = l; r < n; ++r)
            {
                if(l == r)
                    changes[l][r] = 0 ;
                else if(l+1 == r)
                    changes[l][r] = (s[l] != s[r]) ;
                else
                    changes[l][r] = changes[l+1][r-1]+(s[l] != s[r]) ;
            }
        }
        vector<vector<int>> dp(k, vector<int>(n, INT_MAX)) ;
        for(int r = 0; r < n; r++)
            dp[0][r] = min(changes[0][r], dp[0][r]) ;
        for(int kk = 1; kk < k; ++kk)
            for(int l = n-1; l >= kk; --l)
                for(int r = l; r < n; r++)
                    dp[kk][r] = min(dp[kk][r], dp[kk-1][l-1]+changes[l][r]) ;

        return dp[k-1][n-1] ;
    }

};