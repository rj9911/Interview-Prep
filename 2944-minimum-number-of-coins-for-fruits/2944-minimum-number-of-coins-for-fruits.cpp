class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        int firstFruit = prices[0];
        if(n == 1)
            return firstFruit;
        
        //Tabulation 
        vector<vector<int>> dp(n , vector<int> (n , 0));

        //base case for dp
        dp[n-1][0] = prices[n-1];
        //dp[0] cases arent needed because that row is never filled 
        
        for(int i = n - 2; i >= 1; i--){
            for(int free = 0; free < n - 1; free++){
                //calculation part
                int takenFree = 1e9;
                if(free > 0)
                    takenFree = dp[i + 1][free - 1];
                
                int notTakeFree = prices[i] + dp[i + 1][i + 1];

                dp[i][free] = min(takenFree, notTakeFree);
            }
        }

        return dp[1][1] + firstFruit;
    }

};