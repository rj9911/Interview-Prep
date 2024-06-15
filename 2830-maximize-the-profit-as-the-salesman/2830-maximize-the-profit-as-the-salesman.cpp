class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        unordered_map<int,vector<pair<int,int>>>ending;
        //format = for ending at specific number == {starting ,gold}
        for(auto offer:offers){
            ending[offer[1]].push_back({offer[0],offer[2]});
        }

        vector<int>dp(n+1,0);
        //dp[i] represents maximum gold that we can procure from selling houses in range(0,k)

        for(int k=0;k<n;k++){
            dp[k+1]=dp[k];
            if(ending.count(k)){
                for(auto ele:ending[k]){
                    int start=ele.first;
                    int gold=ele.second;
                    //check if this can produce better result
                    dp[k+1]=max(dp[k+1],gold+dp[start]);
                }
            }
            
        }
        return dp[n];
        
    }

};