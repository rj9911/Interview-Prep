class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int res=INT_MAX,n=words.size()-1;
        int dp[1001][26][26]={}; 
        /*
         DP states: dp[i][j][k]
            i  -> current word
            j  -> first letter of the string formed after considering the current word
            k  -> last letter of the string formed after considering the current word
        */
        dp[0][words[0][0]-'a'][words[0].back()-'a']=words[0].length();
        
        for(int i=1;i<=n;i++)
        {
            int b = words[i][0]-'a'; //first letter of current word
            int e = words[i].back()-'a'; //last letter of current word
           
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<26;k++)
                {
                    if(dp[i-1][j][k]>0)
                    { 
                        int l;
                        l=dp[i-1][j][k]+words[i].length();

                        // Concate curr word + prev word
                        if(dp[i][b][k]==0) dp[i][b][k] = (e==j)?l-1:l;
                        else dp[i][b][k] = min((e==j)?l-1:l,dp[i][b][k]);

                        // Concate prev word + curr word
                        if(dp[i][j][e]==0) dp[i][j][e] = (b==k)?l-1:l;
                        else dp[i][j][e] = min((b==k)?l-1:l,dp[i][j][e]);
                    }
                }
            }
        }
        for(int j=0;j<26;j++)
        {
            for(int k=0;k<26;k++)
            {
                if(dp[n][j][k]>0) res=min(res,dp[n][j][k]);
            }
        }
        return res;
    }

};