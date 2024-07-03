class Solution {
public:
    long long maximumTotalDamage(vector<int>& v) {
        map<long long,long long>m;
        for(auto i:v)
            m[i]++;
        vector<pair<int,long long>>temp;
        for(auto i:m) {
            long long k=i.first*i.second;
            temp.push_back({i.first,k});
        }
        int n=temp.size();
        vector<long long>dp(n,0);
        dp[0]=temp[0].second;
        long long ans=dp[0];
        for(int i=1;i<n;i++) {
            int j=i-1,c=8;
            long long k=0;
            while(j>=0 && c>=0) {
                if(temp[j].first+2<temp[i].first) {
                    k=max(k,dp[j]);
                }
                j--;
                c--;
            }
            dp[i]=temp[i].second+k;
            ans=max(ans,dp[i]);
        }
        return ans;
    }

};