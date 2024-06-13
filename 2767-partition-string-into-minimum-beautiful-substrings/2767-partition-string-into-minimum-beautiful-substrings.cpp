class Solution {
    bool isPower(int n){
        while(n > 1){
            if(n % 5 == 0){
                n /= 5;
            }
            else return false;
        }
        return n == 1;
    }
public:
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        if(s[0]=='0') return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for(int index = n - 1; index >= 0; index--){
            if(s[index] == '0') continue;
            int curr_num = 0;
            int ans = INT_MAX;
            for(int i = index; i < n; i++){
                curr_num  = curr_num * 2 + s[i] - '0';
                if(isPower(curr_num)){
                    ans = min(ans, 1 + dp[i + 1]);
                }
            }
            dp[index] = ans;
        }
        int res = dp[0];
        return res >= 1e9 ? -1 : res;
    }

};