class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        if(k==1)return n;

        vector<vector<int>>pd(n+1);
        vector<int> dp(n+1,0);
        for(int i =0 ;i<=n; i++){
            pd[i].push_back(0);
            pd[i].push_back(1); 
        }       

        for(int i = n-2 ; i>=0 ;i--){       
           for(auto len : pd[i+1]){                         
               int toCheck = i+len+1;
               if(toCheck<n){
                   if(s[toCheck]==s[i]){                       
                       pd[i].push_back(len+2);
                       if(len+2>=k)
                        dp[i] = max(dp[i] , 1+dp[toCheck+1]);
                   }
               } 
           }
           
           dp[i] = max(dp[i] , dp[i+1]);
        }   
       return dp[0];
    }

};