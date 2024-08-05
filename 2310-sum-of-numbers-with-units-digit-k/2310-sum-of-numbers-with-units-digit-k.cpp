class Solution {
public:
  int solve(vector<int>coins, int n, int amount){
        int dp[n+1][amount+1];
        for(int i=0; i<=amount; i++){
            dp[0][i] = INT_MAX - 1;
        }
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amount] == INT_MAX-1){
            return -1;
        }
        return dp[n][amount];
    }
    int minimumNumbers(int num, int k) {
        vector<int>coins;
        for(int i=1; i<=num; i++){
            if(i%10 == k){
                coins.push_back(i);
            }
        }
        int x = solve(coins,coins.size(),num);
        return x;
    }

};