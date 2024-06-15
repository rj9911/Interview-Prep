class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        
        int n=nums.size();
        vector<long long> v(n+1,0);
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n; i++)
            v[i]= v[i-1]+nums[i-1];
        
        
        vector<vector<long long>> sk;
        sk.push_back({0,0});
        
        for(int i=1; i<=n; i++)
        {
            int low=0, high=sk.size()-1;
            int p=0;
            
            while(low<=high)
            {
                int mid= low+(high-low)/2;
                
                if(sk[mid][0]<= v[i])
                {
                    p= max(p,mid);
                    low=mid+1;
                }
                else high=mid-1;
            }
            
            int index= sk[p][1];
            
            dp[i]=dp[index]+1;
            
            long long add= 2*v[i]-v[index];
            
            while(sk.back()[0]>=add)
                sk.pop_back();
            
            sk.push_back({add, i});
    
        }
        
        
        return dp[n];
    }

};