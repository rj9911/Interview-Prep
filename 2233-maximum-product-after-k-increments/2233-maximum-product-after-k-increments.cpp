class Solution {
public:
    int maximumProduct(vector<int>& nums, int k)
    {
        const int mod = 1e9+7;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it : nums)
            pq.push(it);
        
        while(k>0)
        {
            int x = pq.top();
            pq.pop();
            pq.push(x+1);
            k--;
        }
        long long  ans = 1;
        while(!pq.empty())
        {
            long long  x = pq.top();
            ans *=x;
            ans%=mod;
            pq.pop();
        }
        return ans;
    }

};