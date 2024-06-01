class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        map<char,vector<int>> mpp;
        for(int i=0;i<n;i++) {
            mpp[s[i]].push_back(i);
        }

        int ans = 0;
        for(auto c: mpp) {
            vector<int> v = c.second;
            int x = 0;
            for(int i=0;i<v.size();i++) {
                int left,right;
                if(v[i]==0) left=1;
                else {
                    left=(i==0) ? v[i]+1 : v[i]-v[i-1];
                }
                if(v[i]==n-1) right=1;
                else {
                    right = (i==v.size()-1) ? n-v[i] : v[i+1]-v[i];
                }
                x += (left*right);
            }
            ans+=x;
        }

        return ans;

    }
};