#define ll long long 

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        
        vector<ll> res;
        
        map<ll, ll> m;
        pair<ll, ll> p;
        priority_queue<pair<ll, ll>> pq;
        
        for(int i=0; i<nums.size(); ++i)
        {
            ll id = nums[i]; int fr = freq[i];
            
            m[id]+=fr;
            
            pq.push({m[id], id});
            
            while(!pq.empty())
            {   
                ll currf = pq.top().first;
                ll currid = pq.top().second;
                
                if(m[currid]!=currf)
                {
                    pq.pop();
                    continue;
                }
                
                else
                {
                    res.push_back(currf);
                    break;
                }
            }
        
        }
        
        return res;
        
    }
};
