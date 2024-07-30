class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) 
    {
        vector<pair<int,int>> ess;
        for(int i=0;i<n;i++)
        {
            ess.push_back({eff[i],speed[i]});
        }
        sort(ess.rbegin(),ess.rend());
        priority_queue<int,vector<int>,greater<int>> pq; //min heap
        long long sum=0,res=0;
        for( auto &[e,s]:ess)
        {
            pq.push(s);
            sum+=s;
            while(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            res=max(res,sum*e);
            
        }
        return res%(int)(1e9+7);
        
    }

};