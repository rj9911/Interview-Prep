class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        
        int n = nums.size();
        // dp i represents what is min cost if I consider array from [0...i]
            
            
        vector<long long> dp(n + 1, 1e13);
        dp[0] = 0;
        dp[1] = k;    
        for(int i = 1; i < n; i ++) {
                vector<int> freq(1001, 0);
                long long cost = 0;
                for(int j = i; j >= 0; j --) {
                        dp[i + 1] = min(dp[i + 1], k + cost + dp[j + 1]);
                        
                        freq[nums[j]]++;
                        if(freq[nums[j]] == 2) {
                                cost += 2;
                        } else if(freq[nums[j]] > 2){
                                cost ++;
                        }
                }
                dp[i + 1] = min(dp[i + 1], k + cost);
             
        }
            
        return dp[n];
    }

};