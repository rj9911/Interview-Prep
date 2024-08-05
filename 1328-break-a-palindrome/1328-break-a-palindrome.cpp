class Solution {
public:
    bool isPal(string &s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    string breakPalindrome(string s) {
        int n=s.size();
        if(n==1)return "";
        for(char c='a';c<='b';c++){
            for(int i=0;i<=n/2;i++){
                if(s[i]==c )continue;
                char tp=s[i];
                s[i]=c;
                if(isPal(s)==false){
                    string ss=s;
                    reverse(s.begin(),s.end());
                    if(ss>s)return s;
                    return ss;
                }
                s[i]=tp;
            }
        }
        return "";
    }

};