class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for(int i = 0; i < n; i++){
            int rem = dist[i] % speed[i];
            dist[i] = dist[i]/speed[i];
            if(rem)
                dist[i] += 1;
        }
        
        sort(dist.begin(), dist.end());
        int t = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(t <= dist[i])
                ans++;
            else
                return ans;
            t++;
        }
        return ans;
    }

};