class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        int temp=0;
        int ans=0;
        while(i<=j && j<n && i<n){
            mp[s[j]]++;
            temp=0;
            for(auto a:mp){
                temp=max(temp,a.second);
            }
            while((j-i+1-temp)>k && i<n && i<=j){
                mp[s[i]]--;
                i++;
            }
            if((j-i+1-temp)<=k){
                ans=max(ans,j-i+1);
                j++;
            } 
        }
        return ans;
    }

};