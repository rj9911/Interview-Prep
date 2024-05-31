class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int> dp(n+1,1);
        vector<int> hash(n+1,1);
        int lastIndex=-1;
        int maxi=-1;
        for(int i=0;i<pairs.size();i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(pairs[i][0]>pairs[prev][1] and 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        
        return maxi;
    }

};