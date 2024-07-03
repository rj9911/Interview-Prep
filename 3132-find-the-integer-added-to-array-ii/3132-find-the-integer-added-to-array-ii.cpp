class Solution {
public:
    int minimumAddedInteger(vector<int>& v1, vector<int>& v2) {
        int ans=INT_MAX;
        int m=v2.size();
        int n=v1.size();
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                vector<int>t;
                for(int k=0;k<n;k++) {
                    if(k!=i && k!=j) {
                        t.push_back(v1[k]);
                    }
                }
                int diff=v2[m-1]-t[m-1];
                int f=0;
                for(int k=m-2;k>=0;k--) {
                    int d=v2[k]-t[k];
                    if(d!=diff) {
                        f=1;
                        break;
                    }
                }
                if(f==0)
                    ans=min(ans,v2[m-1]-t[m-1]);
            }
        }
        return ans;
    }

};