class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& v) {
        int l=0,r=v.size()-1;
        int ans=0;
        while(l<=r){
          int m=(l+r)/2;
          unordered_set<int>se;
          for(int i=0;i<=m;i++){
              se.insert(v[i]);
          }
          int i=0,j=0;
          while(i<s.size() && j<p.size()){
              if(s[i]==p[j] && !se.count(i)){
                  i++;
                  j++;
              }
              else i++;
          }
          if(j==p.size()){
              ans=m+1;
              l=m+1;
          }
          else {
              r=m-1;
          }
        }
        return ans;
    }

};