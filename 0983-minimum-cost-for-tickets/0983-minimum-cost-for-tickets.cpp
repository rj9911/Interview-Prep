class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1,0);

        for(int i=days.size() - 1;i>=0;i--)
        {
            int cost1 = costs[0] + dp[i + 1];
            int idx = i;
            int num_days = days[idx] + 7 - 1;
            while(idx < days.size() && days[idx] <= num_days)
            {
                idx++;
            }
            idx--;
            int cost2 = costs[1] + dp[idx + 1];
            idx = i;
            num_days = days[idx] + 30 - 1;
            while(idx < days.size() && days[idx] <= num_days)
            {
                idx++;
            }
            idx--;
            int cost3 = costs[2] + dp[idx + 1];

            dp[i] = min({cost1,cost2,cost3});
        }

        return dp[0];
    }

};