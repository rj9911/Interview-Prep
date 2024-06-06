class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> memo(target+1, "0"); 
        memo[0] = "";
        for(int cur = 1; cur <= target; ++cur) {
            string ans = "0";
            for(int i=8; i>=0; --i) {
                if(cur < cost[i]) continue;
                string rem = memo[cur - cost[i]];
                if(rem == "0") continue;
                rem = to_string(i+1) + rem;
                if(ans == "0" || ans.size() < rem.size()) ans = rem;
            }
            memo[cur] = ans;
        }
        return memo[target];

    }

};