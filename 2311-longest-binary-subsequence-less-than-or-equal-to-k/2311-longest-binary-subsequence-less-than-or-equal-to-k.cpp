class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(s.begin(), s.end());
        
        int n = s.size();
        
        vector<pair<int, int>> dp(n);
        //len, value pair
        
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '0') {
                dp[i] = {1, 0};
            }
            else {
                dp[i] = {1, 1};
            }
        }
        
        int res = 0;
        
        for(int i = 1 ; i < n ; i++) {
            for(int j = i - 1 ; j >= 0 ; j--) {
                int currLen = dp[j].first;
                int currVal = dp[j].second;
                
                if( s[i] == '1' && (currVal + pow(2, currLen)) <= k) {
                    if((currLen + 1) > dp[i].first) {
                        dp[i].first = currLen + 1;
                        dp[i].second = (currVal + pow(2, currLen));    
                    }   
                }
                else if(s[i] == '0' && currVal <= k){
                    if((currLen + 1) > dp[i].first) {
                        dp[i].first = currLen + 1;
                        dp[i].second = (currVal);    
                    }   
                }
            }
            
            res = max(res, dp[i].first);
        }
        
        if(s.size() == 1)
            return 1;
        
        return res;    
    }

};