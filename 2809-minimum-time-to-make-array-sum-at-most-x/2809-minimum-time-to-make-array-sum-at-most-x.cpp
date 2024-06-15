class Solution {
public:
    int minimumTime(vector<int>& a, vector<int>& b, int x) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0); cerr.tie(0);
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        int add = accumulate(b.begin(), b.end(), 0);
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++) v[i] = {b[i], a[i]};
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) b[i] = v[i].first, a[i] = v[i].second;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1));
        if(sum <= x) return 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] + b[i - 1] * j);
            }
        }
        for(int i = 1; i <= n; i++){
            if(sum + add * i - dp[n][i] <= x) return i;
        }
        return -1;
    }

};