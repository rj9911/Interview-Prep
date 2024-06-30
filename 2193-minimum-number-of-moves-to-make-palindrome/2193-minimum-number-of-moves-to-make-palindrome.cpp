class Solution {
public:
 int minMovesToMakePalindrome(string s) {
        int l,r,n,cnt=0;
        n=s.length();
        l=0;
        r=n-1;
        
        while(l<r){
            if(s[l] == s[r]){
                l++;
                r--;
                continue;
            }
            
            int idx=r;
            while(idx>l && s[idx] != s[l])
                idx--;
            
            if(idx == l){
                // This means odd case, Just swap it with itself and do not need to go further
                swap(s[idx], s[idx+1]);
                cnt++;
                continue;
            }
            
            while(idx<r){
                swap(s[idx],s[idx+1]);
                cnt++;
                idx++;
            }
            l++;
            r--;
        }
        return cnt;
    }

};