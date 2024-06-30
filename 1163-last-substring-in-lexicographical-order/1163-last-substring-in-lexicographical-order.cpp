class Solution {
public:
    string lastSubstring(string s) {
        int n=s.length();
        int maxidx=n-1;
        
        for(int i=n-2;i>=0;i--){
            if(s[i]>s[maxidx]){
                maxidx=i;
            }
            else if(s[i]==s[maxidx]){
                if(maxidx==n-1){
                    maxidx=i;
                }
                else{
                    int j=1;
                    while((maxidx+j<n) && s[i+j]==s[maxidx+j] && (i+j)!=maxidx ){
                        j++;
                    }
                    if(s[i+j]>=s[maxidx+j] || (maxidx+j)>=n){
                        maxidx=i;
                    }
                }
            }
        }
        return s.substr(maxidx);
    }

};