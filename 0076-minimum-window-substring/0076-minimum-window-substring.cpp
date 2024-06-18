class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size() || t=="") return "";
        vector<int> counting(128,0);
        vector<int> window(128,0);
        int count=0;
        for(char c:t) {
            counting[c-'A']++;
            if(counting[c-'A']==1) count++;
        }
        int l=0,r=0;
        int matches=0;
        int len=INT_MAX;
        int ans=0;
        while(r<s.size()) {
            window[s[r]-'A']++;
            if(window[s[r]-'A']==counting[s[r]-'A']) {
                matches++;
            }
            while(matches==count) {
                if((r-l+1)<len) {
                    len=r-l+1;
                    ans=l;
                }
                window[s[l]-'A']--;
                if(window[s[l]-'A']<counting[s[l]-'A']) {
                    matches--;
                }
                l++;
            }
            r++;
        }
        if(len!=INT_MAX) return s.substr(ans,len);
        else return "";
    }

};