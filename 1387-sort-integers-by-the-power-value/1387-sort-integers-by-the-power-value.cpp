class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int>dp(3001,0);
        dp[1] = 0;
        for(int i=2;i<=min(3000,hi);i++){
            int count = 0;
            int x = i;
            while(x!=1){
                if(x&1){
                    count++;
                    x = x*3+1;
                }
                else {
                    count++;
                    if(x/2<i){
                        count+=dp[x/2];
                    break;
                    }
                    else x/=2;
                }
            }
            dp[i] = count;
        }
        vector<pair<int,int>>v;
        for(int i=lo;i<=hi;i++)v.push_back({dp[i],i});
        sort(v.begin(),v.end());
        return v[k-1].second;
    }

};