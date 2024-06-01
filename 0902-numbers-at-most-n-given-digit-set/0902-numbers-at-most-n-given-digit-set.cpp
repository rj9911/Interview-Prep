class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        long long ans=0;

        string st=to_string(n);
        int i,j;
        int len=st.length();        
        int m=digits.size();
        vector<vector<int>> dp(len,vector<int>(2,0));        
       for(i=len-1;i>=0;i--)
        {
            for(j=0;j<m;j++)
            {
                if((int)digits[j][0]>=(int)st[i])
                break;
            }
            int p=j,cc=0;
            if(j!=m&&digits[j][0]==st[i])
            cc=1;
            if(i==len-1)
            {
                dp[i][0]=m;
                dp[i][1]=p+cc;
            }
            else
            {
                dp[i][0]=m*dp[i+1][0];
                dp[i][1]=p*dp[i+1][0]+cc*dp[i+1][1];
            }
            if(i!=0)
            ans+=dp[i][0];
            else
            ans+=dp[i][1];
        }
        return ans;
    }

};