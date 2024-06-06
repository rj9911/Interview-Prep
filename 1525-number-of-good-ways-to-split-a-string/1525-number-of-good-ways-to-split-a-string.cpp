class Solution {
public:
    int numSplits(string s) {
        if(s.size()<2) return 0;
        unordered_map<char,int> mp,left;
        for(auto& ch:s)
            mp[ch]++;
        int l=1, k=mp.size();
        left[s[0]]++;
        if(--mp[s[0]]==0) k--;
        int ans=0;
        if(l==k) ans++;
        for(int i=1; i<s.size()-1; i++){
            if(!left.count(s[i])) l++;
            left[s[i]]++;
            if(--mp[s[i]]==0) k--;
            if(l==k) ans++;
        }
        return ans;
    }


};