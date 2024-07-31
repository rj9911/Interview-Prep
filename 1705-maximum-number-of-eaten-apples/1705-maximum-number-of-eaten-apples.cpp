class Solution {
public:
    int eatenApples(vector<int>& a, vector<int>& d) {
        int n  = a.size(),ans = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++)
        {
            if(a[i]>0) pq.push({-1*(i+d[i]),a[i]});
            while(!pq.empty() && abs(pq.top().first)<=i) pq.pop();
            if(pq.size()>0)
            {
              int day = abs(pq.top().first);
              int apple = pq.top().second;
              pq.pop();
              if(day>i)
              {
              ans+=1;
              if(apple-1 > 0) pq.push({-1*day,apple-1});
              }
            }
        }
        int i = n;
        while(!pq.empty())
        {
            int day = abs(pq.top().first);
            int apple = pq.top().second;
            pq.pop();
            if(day>i)
            {
              ans+=1;
              i++;
              if(apple-1 > 0) pq.push({-1*day,apple-1});
            }
        }
        return ans;  
    }

};