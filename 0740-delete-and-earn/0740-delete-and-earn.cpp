class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums) m[i]++;

        vector<int> v;
        for(auto i : m) v.push_back(i.first);
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int> dp(n + 1);

        for(int i=n-1; i>=0; i--) {
            int notpick = 0 + dp[i + 1];
            int pick = m[v[i]] * v[i];
            if(i + 1 < n && v[i] + 1 == v[i + 1]) pick += dp[i + 2];
            else if(i + 1 < n && v[i] + 1 != v[i + 1]) pick += dp[i + 1];
            dp[i] = max(pick, notpick);
        }
        return dp[0];
    }

};