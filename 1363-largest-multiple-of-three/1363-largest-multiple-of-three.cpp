class Solution {
public:
    static bool cmp(const int& a, const int& b) 
    {
        return a > b;
    }
    string largestMultipleOfThree(vector<int>& a) { 
        sort(a.begin(), a.end(), cmp);
        int n = a.size(); 
        int dp[n + 1][3]; 
        dp[n][0] = 0; dp[n][1] = -1; dp[n][2] = -1; 
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = 0; j < 3; j++) 
            {
                dp[i][j] = dp[i + 1][j]; 
                int tmp = dp[i + 1][(j + a[i]) % 3];  
                if (tmp != -1) 
                {
                    dp[i][j] = max(dp[i][j], tmp + 1);
                }
                
            }
        } 
        if (dp[0][0] == 0) 
        {
            return "";
        } 
        string res; 
        int mod = 0; 
        for (int i = 0; i < n; i++) 
        {
            if (dp[i + 1][(mod + a[i]) % 3] != -1 && dp[i][mod] == dp[i + 1][(mod + a[i]) % 3] + 1) 
            {
                res.push_back(a[i] + '0'); 
                mod = (mod + a[i]) % 3;
            }
        }
        return res[0] == '0' ? "0" : res;
    }

};