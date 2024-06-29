class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>>v(s.size(), vector<int>(s.size(), 0));
        for(int i=0; i<s.size(); i++){
            v[i][i]=1;
        }
        for(int i=1; i<s.size(); i++){
            for(int j=0, k=i; j<s.size() && k<s.size(); j++, k++){
                if(s[j]==s[k]){
                    if(k-j>1){
                        if(v[j+1][k-1]!=0){
                            v[j][k]=2+v[j+1][k-1];
                        }
                    }
                    else if(k-j==1){
                        v[j][k]=2;
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(v[i][j]>0)cnt++;
            }
        }
        return cnt;
    }

};