class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<int> best(18, INT_MAX);  
        int n = tires.size();
        int maxdiff = 0;
        for (int i = 0; i < n; ++i) {
            long time = tires[i][0], lap = tires[i][0];
            for (int j = 1; lap < changeTime + tires[i][0]; ++j) {
                best[j] = min(best[j], static_cast<int>(time));
                lap *= tires[i][1];
                time += lap;
                maxdiff = max(maxdiff, j);
            }
        }

        vector<int> f(numLaps + 1, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = i - 1; j >= 0 && i - j <= maxdiff; --j) {
                f[i] = min(f[i], f[j] + changeTime + best[i - j]);
            }
        } 
        return f[numLaps] - changeTime;
    }

};