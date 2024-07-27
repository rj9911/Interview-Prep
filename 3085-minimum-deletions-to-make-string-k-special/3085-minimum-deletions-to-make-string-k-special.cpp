class Solution {
public:
    int minimumDeletions(string word, int k) {
         unordered_map<char,int>mp;
        for(auto it:word) mp[it]++;
        int ans=INT_MAX;
        for(auto it:mp){
            int res=0;
            int limit=it.second;
            for(auto it:mp){
                if(it.second>limit+k){
                    res+=it.second-(limit+k);
                }
                else if(it.second<limit)res+=it.second; // see again
            }
            if(ans==0) break;
            ans=min(ans,res);
        }
        if(ans==INT_MAX) return 0;
        return ans;
        
    }
};