class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>>>>pq;

        int m = values.size();
        int n = values[0].size();
        for(int i =0;i<m;i++){
            pq.push({values[i][n-1],{i,n-1}});
        }
        int day = 1;
        long long ans = 0;
    
        while(!pq.empty()){
            auto it = pq.top();
            int val = it.first;
            int r = it.second.first;
            int c = it.second.second;
            ans += (long long)val*day;
            pq.pop();
            if(c-1>=0){
                pq.push({values[r][c-1],{r,c-1}});
            }
            day++;
        }
        return ans;
    }

};