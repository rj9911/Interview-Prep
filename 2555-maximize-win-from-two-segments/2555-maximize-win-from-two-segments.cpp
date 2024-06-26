class Solution {
public:
    int maximizeWin(vector<int>& a, int k) {
        int n = (int)a.size();
        vector<int>dp(n,0);
        for(int i = 0 ; i < n ; i++) {
        //Calculates the maximum number of prizes we can collect if we start at index i.

         int p = upper_bound(a.begin(),a.end(),a[i] + k) - a.begin(); // binary search to find the first index that cannot be included
         int len = p - i; // length of the segment that can included we start at index i.
         dp[i] = len; // storing the best possible answer if we start collecting prizes if we start at index i.
        }      
        vector<int>dp2 = dp;
        int mx = dp[n-1];
        for(int i = n-1 ; i >= 0 ; i--) {
            mx = max(dp[i],mx);
            dp2[i] = mx; // creating suffix maximum array.
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
         int res = dp[i]; // gives the maximum number of prizes we can take if we start at index i [Segment 1]. (marked blue & red in picture)
         if(i+dp[i] < n) {
            // Maximum possible value for Segment 2 (marked as pink in picture)
            res += dp2[i+dp[i]]; 
         }
         ans = max(ans,res); // maximum possible answer.
        }
        return ans;
    }

};