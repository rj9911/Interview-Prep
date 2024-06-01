class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long n = stations.size();
        vector<long long> dp (n+1,0), picked (n,0);
        // maxm distance i can go if i pick 'i' stations

        dp[0] = startFuel; //base case

        for (int i=1; i<=n; i++) {
            long long idxpicked = -1;
            for (int j=0; j<n; j++) {
                if (picked[j]) continue;
                if (dp[i-1]>=stations[j][0]) {
                    if (idxpicked==-1 || stations[j][1] > stations[idxpicked][1]) {
                        idxpicked = j;
                    }
                }
            }
            if (idxpicked==-1) break; //can't select any further station (all are out of limit)
            dp[i] = dp[i-1] + stations[idxpicked][1]; // add this gas to prev maxm gas
            picked[idxpicked] = 1; //mark it as picked
        }

        for (int i=0; i<=n; i++) {
            if (dp[i]>=target) return i; //return minm 'i' (no. of stations) we need to reach target
        }

        return -1;
    }

};