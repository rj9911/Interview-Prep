class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)pq.push({nums[i],i});

        int lo=0,hi=n-1;
        maxi=(pq.top().first)*n;
        
        while(lo<=k&&hi>=k){
            auto x=pq.top();
            pq.pop();
            if(k>x.second)lo=max(x.second+1,lo);
            else hi=min(hi,x.second-1);
            if(lo>k||hi<k)continue;
            maxi=max(maxi,(hi-lo+1)*pq.top().first);
        }
        return maxi;
    }

};