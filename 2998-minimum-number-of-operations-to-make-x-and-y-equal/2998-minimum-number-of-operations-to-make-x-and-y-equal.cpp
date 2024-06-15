class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y >=x) return y-x;
        else{
            vector<int> dp(x+20, INT_MAX-1);
            for(int i = 0; i <= x+11; i++){
                if(y>=i) dp[i] = y - i;
                else{
                    int a = dp[i-1]+1, b = INT_MAX-1, c= INT_MAX-1;
                    if(i%5 == 0) b = dp[i/5]+1;
                    if(i%11 == 0) c = dp[i/11]+1;
                    dp[i] = min(a, min(b,c));
                    
                }
                if(i!=0) dp[i-1] = min(dp[i-1], dp[i]+1);
            }
            for(int i = x+10; i>=x; i--){
                dp[i] = min(dp[i], dp[i+1]+1);
            }
            return dp[x];
        }
    }

};