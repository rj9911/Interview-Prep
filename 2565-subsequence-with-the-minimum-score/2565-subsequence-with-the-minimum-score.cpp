class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.length(),i=0,j=0,m = t.length();
        vector<int> p(n,0),su(n,0);
        for(i = 0; i < n&&j<m; i++){
            if(s[i]==t[j]){
                j++;
                p[i]++;
            }
            if(i){
                p[i] += p[i-1];
            }
        }
        j = m-1;
        for(i = n-1; i >=0&&j>=0; i--){
            if(s[i]==t[j]){
                j--;
                su[i]++;
            }
            if(i!=n-1){
                su[i] += su[i+1];
            }
        }
        int ans = n+10;
        // for(auto &i: p)cout<<i<<" ";cout<<endl;
        // for(auto &i: su)cout<<i<<" ";cout<<endl;
        // cout<<n-su[0]<<" ";
        for(i = 0; i < n-1; i++){
            // cout<<n-p[i]-su[i+1]<<" ";
            ans = min(ans,m-(p[i]+su[i+1]));
        }
        // cout<<n-p[n-1];
        ans = min(ans,m-p[n-1]);
        ans = min(ans,m-su[0]);
        return max(ans,0);
    }

};