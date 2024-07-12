class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), len = 0;
        vector<vector<int>> dp(n,vector<int>(n));

        for(int i=2;i<n;i++){
            int l = 0, r = i - 1;
            while(l < r) {
                int sum = arr[l] + arr[r];
                if(sum < arr[i]) l++;
                else if(sum > arr[i]) r--;
                else {
                    dp[r][i] = 1 + dp[l][r];
                    len = max(len,dp[r][i]);
                    l++,r--;
                }
            }
        }

        if(len != 0) return len + 2;
        return 0;
    }

};