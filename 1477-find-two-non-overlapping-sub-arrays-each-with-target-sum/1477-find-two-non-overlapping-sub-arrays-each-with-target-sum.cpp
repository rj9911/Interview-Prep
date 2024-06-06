class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int ans = 2 * arr.size(), cur = 0;
        vector<int> dp (arr.size() + 1, 2 * arr.size());  // because of dp[i-1], add a trivail value be index -1
        unordered_map<int, int> prefix;
        prefix[0] = -1;
        for (int i = 0, leng; i < arr.size(); i+=1) {
            cur += arr[i];
            if (prefix.count(cur - target) != 0) {
                leng = i - prefix[cur - target];
                dp[i+1] = min(dp[i], leng);
                ans = min(ans, leng + dp[prefix[cur - target] + 1]);
                
            } else dp[i+1] = dp[i];
            prefix[cur] = i;
        }
        return ans != 2 * arr.size()? ans :-1;
    }

};