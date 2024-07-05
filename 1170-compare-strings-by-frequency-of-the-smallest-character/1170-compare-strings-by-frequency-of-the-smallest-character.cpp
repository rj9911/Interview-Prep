class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        map<char,int>mp;
        vector<int>p,r,ans;
        for(int i=0;i<q.size();i++){
            mp.clear();
            for(int j=0;j<q[i].length();j++)mp[q[i][j]]++;
            int k=0;
            for(auto i:mp){k=i.second;break;}
            p.push_back(k);
        }
        for(int i=0;i<w.size();i++){
            mp.clear();
            for(int j=0;j<w[i].length();j++)mp[w[i][j]]++;
            int k=0;
            for(auto i:mp){k=i.second;break;}
            r.push_back(k);
        }
        for(int i=0;i<p.size();i++){
            int x=0;
            for(int j=0;j<r.size();j++)if(p[i]<r[j])x++;
            ans.push_back(x);
        }
        return ans;
    }


};