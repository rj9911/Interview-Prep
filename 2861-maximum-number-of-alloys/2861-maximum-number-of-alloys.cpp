class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int coins, vector<vector<int>>& grid, vector<int>& stock, vector<int>& cost) {
        long long l=0,r=1e9,ans;
        while(l<=r)
        {
           long long mn=1e18;
            long long mid=(l+r)/2LL;
            for(auto it:grid){
                long long x=0;
                for(int i=0;i<n;i++){
                    long long y=(long long)(it[i]*mid-stock[i]);
                    if(y>0){
                        x+=(long long)(cost[i]*y);
                }
                }
                mn=min(x,mn);
            }
            if(mn<=coins){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }

};