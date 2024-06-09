class Solution {
public:
    bool isprime(char c) {
        return c=='2'||c=='3'||c=='5'||c=='7';
    }
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        if (!isprime(s[0]) || isprime(s[n-1])){return 0;}
        if (n<minLength){return 0;}
        if (k==1){return 1;}
        vector<int> primeid;
        for (int i=minLength;i<=n-minLength;i++){
            if (isprime(s[i])&&!isprime(s[i-1])){
                primeid.push_back(i);
            }
        }
        int mod = 1000000007;
        int ln = primeid.size();
        if (ln<k-1){return 0;}
        int dp1[ln], dp[ln];
        for (int i=0;i<ln;i++){
            dp1[i]=i+1;
            dp[i]=0;
            }
        for (int ik=2;ik<k;ik++){
            for (int i=ik-1;i<ln;i++){
                dp[i] = dp[i-1];
                for (int j=i-1;j>-1;j--){
                    if (primeid[i]-primeid[j]>=minLength){
                        dp[i] = (dp[i]+dp1[j])%mod;
                        break;
                    }
                }
            }
            for (int i=0;i<ln;i++){
                dp1[i]=dp[i];
                dp[i]=0;
            }
        }
        return dp1[ln-1];        
    }

};