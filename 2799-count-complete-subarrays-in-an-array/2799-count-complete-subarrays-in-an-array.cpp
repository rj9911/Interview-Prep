class Solution {
public:
    int countCompleteSubarrays(vector<int>& v) {
        int n=v.size();
        map<int,int>m;
        for(auto i:v)
            m[i]++;
        int d=m.size();
        m.clear();
        int c=0;
        int i=0,j=0;
        while(i<n && j<n)
        {
            m[v[j]]++;
            while(i<=j && m.size()==d)
            {
                c=c+n-j;
                m[v[i]]--;
                if(m[v[i]]==0)
                    m.erase(v[i]);
                i++;
            }
            j++;
        }
        return c;
    }

};