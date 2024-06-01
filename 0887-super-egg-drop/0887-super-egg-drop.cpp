class Solution {
public:
    int superEggDrop(int k,int n){
        vector<vector<int>>dp(k+2,vector<int>(n+2,0));
        for(int i=0;i<=n;i++){
            int mini=INT_MAX;
            for(int egg=1;egg<=k;egg++){
                if(i==0 or i==1)
                    dp[egg][i]=i;
                else if(egg==1)
                    dp[egg][i]=i;
                else{
                    int low=1,high=i;
                    while(low<=high){
                        int mid=(low+high)/2;
                        int left=dp[egg-1][mid-1];
                        int right=dp[egg][i-mid];
                        if(left<right)
                            low=mid+1;
                        else
                            high=mid-1;
                        mini=min(mini,1+max(left,right));
                    }
                    dp[egg][i]=mini;
                }
            }
        }
        return dp[k][n];
    }

};